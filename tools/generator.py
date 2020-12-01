from pathlib import Path
from enum import Enum
from re import compile as regex_compile
from subprocess import call


class Tok(Enum):
    KW_TYPE = 1
    KW_END_TYPE = 2
    KW_ENTITY = 3
    KW_END_ENTITY = 4
    KW_SCHEMA = 5
    KW_END_SCHEMA = 6

    KW_WHERE = 7
    KW_INVERSE = 8
    KW_UNIQUE = 9
    KW_DERIVE = 10
    KW_FIXED = 11
    KW_OF = 12
    KW_OPTIONAL = 13
    KW_EXISTS = 14

    KW_REAL = 15
    KW_INTEGER = 16
    KW_NUMBER = 17
    KW_STRING = 18
    KW_BINARY = 19
    KW_BOOLEAN = 20
    KW_LOGICAL = 21
    KW_ARRAY = 22
    KW_LIST = 23
    KW_SET = 24
    KW_ENUMERATION = 25
    KW_SELECT = 26

    KW_OR = 27
    KW_AND = 28
    KW_NOT = 29
    KW_SIZEOF = 30
    KW_SELF = 31
    KW_ABSTRACT = 32
    KW_SUBTYPE = 33
    KW_TYPEOF = 34
    KW_QUERY = 35

    NUMBER = 36
    STRING_LITERAL = 37
    COMMENT = 38
    IDENTIFIER = 39

    L_CURLY = 40
    R_CURLY = 41
    L_BRACKET = 42
    R_BRACKET = 43
    L_PAREN = 44
    R_PAREN = 45

    GREATER_THAN = 46
    LESS_THAN = 47
    GREATER_OR_EQUAL = 48
    LESS_OR_EQUAL = 49
    DIAMOND = 50
    LESS_STAR = 51

    PLUS = 52
    MINUS = 53
    TIMES = 54
    DIVIDED = 55

    ASSIGN = 56
    DOT = 57
    PIPE = 58
    BACKSLASH = 59
    COMMA = 60
    WHITESPACE = 61
    EQUAL = 62
    COLON = 63
    SEMI_COLON = 64
    QUESTION_MARK = 65
    UNKNOWN = 66
    EOF = 67


class Token(object):
    def __init__(self, kind, value):
        self.kind = kind
        self.value = value


class Lexer(object):
    def __init__(self, rules, file_name):
        idx = 1
        regex_parts = []
        self.group_kind = {}

        for regex, kind in rules:
            groupname = "GROUP%s" % idx
            regex_parts.append("(?P<%s>%s)" % (groupname, regex))
            self.group_kind[groupname] = kind
            idx += 1

        self.regex = regex_compile("|".join(regex_parts))
        self.re_ws_skip = regex_compile("\S")
        self.buf = Path(file_name).read_text()
        self.pos = 0

    def __token(self):
        if self.pos >= len(self.buf):
            return None

        match = self.re_ws_skip.search(self.buf, self.pos)
        if match:
            self.pos = match.start()
        else:
            return None

        match = self.regex.match(self.buf, self.pos)
        if match:
            groupname = match.lastgroup
            kind = self.group_kind[groupname]
            tok = Token(kind, match.group(groupname))
            self.pos = match.end()
            return tok

        return Token(Tok.UNKNOWN, None)

    def tokenize(self):
        while 1:
            tok = self.__token()
            if tok is None: break
            yield tok
            if tok.kind == Tok.UNKNOWN: break


class DepInfo(object):
    def __init__(self, identifier, dependencies, data):
        self.identifier = identifier
        self.dependencies = dependencies
        self.data = data


class Parser(object):
    def __init__(self, rules, primitives, file_name):
        self.lexer = Lexer(rules, file_name)
        self.primitives = primitives
        self.types = []
        self.entity_pointers = []
        self.forward_entities = []
        self.entities = []
        self.factory_entities = []

    def write_to_file(self):
        self.__write_to_file("ForwardTemplate.h", "../src/import/ifc/external/Forward.h", self.forward_entities)
        self.__write_to_file("PointersTemplate.h", "../src/import/ifc/external/Pointers.h", self.entity_pointers)
        self.__write_to_file("TypesTemplate.h", "../src/import/ifc/external/Types.h",
                             self.__resolve_dependencies(self.types))
        self.__write_to_file("EntitiesTemplate.h", "../src/import/ifc/external/Entities.h",
                             self.__resolve_dependencies(self.entities))
        self.__write_to_file("FactoryTemplate.cpp", "../src/import/ifc/Factory.cpp", self.factory_entities, ",")

    def __resolve_dependencies(self, elements):
        resolved = []
        for info in elements:
            self.__add_sorted(resolved, info, elements)
        return resolved

    def __add_sorted(self, resolved, info, elements):
        if info.data not in resolved:
            for dependency in info.dependencies:
                for elem in elements:
                    if elem.identifier == dependency:
                        self.__add_sorted(resolved, elem, elements)
            if info.data not in resolved:
                resolved.append(info.data)

    def __write_to_file(self, template, output, elements, delimiter="\n"):
        temp_file = Path("temp")
        temp_file.write_text(Path(template).read_text().format(delimiter.join(elements)))
        with open(output, "w") as f:
            call(["clang-format", "temp"], stdout=f)
        temp_file.unlink()

    def parse(self):
        token_generator = self.lexer.tokenize()
        for tok in token_generator:
            if tok.kind == Tok.KW_TYPE:
                self.__parse_type(token_generator)
            elif tok.kind == Tok.KW_ENTITY:
                self.__parse_entity(token_generator)

    def __parse_type(self, token_generator):
        tok = next(token_generator)
        assert tok.kind == Tok.IDENTIFIER

        identifier = tok.value
        assert next(token_generator).kind == Tok.EQUAL

        tok = next(token_generator)

        if tok.kind in self.primitives:
            typedef = DepInfo(identifier, [], "using {} = {};".format(identifier, self.primitives[tok.kind]))
            self.types.append(typedef)
        elif tok.kind == Tok.KW_LIST or tok.kind == Tok.KW_ARRAY:
            assert next(token_generator).kind == Tok.L_BRACKET
            assert next(token_generator).kind == Tok.NUMBER
            assert next(token_generator).kind == Tok.COLON

            tok = next(token_generator)
            count = 4
            if tok.kind == Tok.NUMBER:
                count = tok.value

            assert next(token_generator).kind == Tok.R_BRACKET
            assert next(token_generator).kind == Tok.KW_OF

            tok = next(token_generator)
            is_primitive = tok.kind in self.primitives
            value_type = self.primitives[tok.kind] if is_primitive else tok.value
            typedef = DepInfo(identifier, [] if is_primitive else [tok.value],
                              "using {} = SmallVector<{}, {}>;".format(identifier, value_type, count))
            self.types.append(typedef)
        elif tok.kind == Tok.KW_ENUMERATION:
            assert next(token_generator).kind == Tok.KW_OF
            assert next(token_generator).kind == Tok.L_PAREN

            value_types = []
            for tok in token_generator:
                if tok.kind == Tok.IDENTIFIER:
                    if tok.value == "NULL":
                        value_types.append("IFC_NULL")
                    else:
                        value_types.append(tok.value)
                elif tok.kind == Tok.R_PAREN:
                    break

            typedef = DepInfo(identifier, [], "\nenum class {} {{ {} }};\n".format(identifier, ", ".join(value_types)))
            self.types.append(typedef)
        elif tok.kind == Tok.KW_SELECT:
            assert next(token_generator).kind == Tok.L_PAREN

            value_types = []
            for tok in token_generator:
                if tok.kind == Tok.IDENTIFIER:
                    value_types.append(tok.value)
                elif tok.kind == Tok.R_PAREN:
                    break

            typedef = DepInfo(identifier, value_types,
                              "\nusing {} = std::variant<{}>;\n".format(identifier, ", ".join(value_types)))
            self.types.append(typedef)
        elif tok.kind == Tok.KW_LOGICAL:
            typedef = DepInfo(identifier, [], "\nenum class {} {{ TRUE, FALSE, UNKNOWN }};\n".format(identifier))
            self.types.append(typedef)
        elif tok.kind == Tok.KW_SET:
            assert next(token_generator).kind == Tok.L_BRACKET
            assert next(token_generator).kind == Tok.NUMBER
            assert next(token_generator).kind == Tok.COLON
            next(token_generator)
            assert next(token_generator).kind == Tok.R_BRACKET
            assert next(token_generator).kind == Tok.KW_OF

            tok = next(token_generator)
            is_primitive = tok.kind in self.primitives
            value_type = self.primitives[tok.kind] if is_primitive else tok.value
            typedef = DepInfo(identifier, [] if is_primitive else [tok.value],
                              "using {} = std::unordered_set<{}>;".format(identifier, value_type))
            self.types.append(typedef)
        elif tok.kind == Tok.IDENTIFIER:
            typedef = DepInfo(identifier, [tok.value], "using {} = {};".format(identifier, tok.value))
            self.types.append(typedef)

    def __parse_entity(self, token_generator):
        tok = next(token_generator)
        identifier = tok.value
        assert tok.kind == Tok.IDENTIFIER

        super_type = "IfcEntity"
        members = ""

        self.factory_entities.append("{{\"{}\", IFC_ALLOCATE_ENTITY({})}}".format(tok.value.upper(), tok.value));
        self.forward_entities.append("struct {};".format(tok.value))
        self.entity_pointers.append("using {} = internal::{}*;".format(tok.value, tok.value))

        for tok in token_generator:
            if tok.kind == Tok.KW_SUBTYPE:
                assert next(token_generator).kind == Tok.KW_OF
                assert next(token_generator).kind == Tok.L_PAREN

                tok = next(token_generator)
                assert tok.kind == Tok.IDENTIFIER
                super_type = tok.value

                assert next(token_generator).kind == Tok.R_PAREN

            elif tok.kind == Tok.SEMI_COLON:
                break

        for tok in token_generator:
            if tok.kind in [Tok.KW_END_ENTITY, Tok.KW_WHERE, Tok.KW_INVERSE, Tok.KW_UNIQUE, Tok.KW_DERIVE]:
                break

            elif tok.kind == Tok.IDENTIFIER:
                assert next(token_generator).kind == Tok.COLON
                member_type = self.__parse_member_type(token_generator)
                assert member_type
                members += "{} {};".format(member_type, tok.value)

                for tok in token_generator:
                    if tok.kind == Tok.SEMI_COLON:
                        break

        entity = DepInfo(identifier, [super_type],
                         "\nstruct {} : {} {{{}}};\n".format(identifier, "ifc::internal::" + super_type, members))
        self.entities.append(entity)

    def __parse_member_type(self, token_generator):
        tok = next(token_generator)

        if tok.kind == Tok.KW_OPTIONAL or tok.kind == Tok.KW_UNIQUE:
            return self.__parse_member_type(token_generator)
        elif tok.kind in self.primitives:
            return self.primitives[tok.kind]
        elif tok.kind == Tok.KW_LOGICAL:
            return "ifc::IfcLogical"
        elif tok.kind == Tok.IDENTIFIER:
            return "ifc::" + tok.value
        elif tok.kind == Tok.KW_LIST or tok.kind == Tok.KW_ARRAY:
            assert next(token_generator).kind == Tok.L_BRACKET
            assert next(token_generator).kind == Tok.NUMBER
            assert next(token_generator).kind == Tok.COLON

            tok = next(token_generator)
            count = 4
            if tok.kind == Tok.NUMBER:
                count = tok.value

            assert next(token_generator).kind == Tok.R_BRACKET
            assert next(token_generator).kind == Tok.KW_OF

            value_type = self.__parse_member_type(token_generator)
            return "SmallVector<{}, {}>".format(value_type, count)
        elif tok.kind == Tok.KW_SET:
            assert next(token_generator).kind == Tok.L_BRACKET
            assert next(token_generator).kind == Tok.NUMBER
            assert next(token_generator).kind == Tok.COLON
            next(token_generator)
            assert next(token_generator).kind == Tok.R_BRACKET
            assert next(token_generator).kind == Tok.KW_OF

            tok = next(token_generator)
            value_type = self.primitives[tok.kind] if tok.kind in self.primitives else "ifc::" + tok.value
            return "std::unordered_set<{}>".format(value_type)

        return None


if __name__ == "__main__":
    rules = [
        # keywords
        (r"\bTYPE\b", Tok.KW_TYPE),
        (r"\bEND_TYPE\b", Tok.KW_END_TYPE),
        (r"\bENTITY\b", Tok.KW_ENTITY),
        (r"\bEND_ENTITY\b", Tok.KW_END_ENTITY),
        (r"\bSCHEMA\b", Tok.KW_SCHEMA),
        (r"\bEND_SCHEMA\b", Tok.KW_END_SCHEMA),

        (r"\bWHERE\b", Tok.KW_WHERE),
        (r"\bINVERSE\b", Tok.KW_INVERSE),
        (r"\bUNIQUE\b", Tok.KW_UNIQUE),
        (r"\bDERIVE\b", Tok.KW_DERIVE),
        (r"\bFIXED\b", Tok.KW_FIXED),
        (r"\bOF\b", Tok.KW_OF),
        (r"\bOPTIONAL\b", Tok.KW_OPTIONAL),
        (r"\bEXISTS\b", Tok.KW_EXISTS),

        (r"\bREAL\b", Tok.KW_REAL),
        (r"\bINTEGER\b", Tok.KW_INTEGER),
        (r"\bNUMBER\b", Tok.KW_NUMBER),
        (r"\bSTRING\b", Tok.KW_STRING),
        (r"\bBINARY\b", Tok.KW_BINARY),
        (r"\bBOOLEAN\b", Tok.KW_BOOLEAN),
        (r"\bLOGICAL\b", Tok.KW_LOGICAL),
        (r"\bARRAY\b", Tok.KW_ARRAY),
        (r"\bLIST\b", Tok.KW_LIST),
        (r"\bSET\b", Tok.KW_SET),
        (r"\bENUMERATION\b", Tok.KW_ENUMERATION),
        (r"\bSELECT\b", Tok.KW_SELECT),

        (r"\bOR\b", Tok.KW_OR),
        (r"\bAND\b", Tok.KW_AND),
        (r"\bNOT\b", Tok.KW_NOT),

        (r"\bABSTRACT\b", Tok.KW_ABSTRACT),
        (r"\bSUBTYPE\b", Tok.KW_SUBTYPE),
        (r"\bTYPEOF\b", Tok.KW_TYPEOF),
        (r"\bSIZEOF\b", Tok.KW_SIZEOF),
        (r"\bSELF\b", Tok.KW_SELF),
        (r"\bQUERY\b", Tok.KW_QUERY),

        # variables
        (r"\(\*[\s\S]+?\*\)", Tok.COMMENT),
        (r"\'[\s\S]+?\'", Tok.STRING_LITERAL),
        (r"\d+(\.\d*)?", Tok.NUMBER),
        (r"[_0-9a-zA-Z]+", Tok.IDENTIFIER),

        # special characters
        (r"\{", Tok.L_CURLY),
        (r"\}", Tok.R_CURLY),
        (r"\[", Tok.L_BRACKET),
        (r"\]", Tok.R_BRACKET),
        (r"\(", Tok.L_PAREN),
        (r"\)", Tok.R_PAREN),

        (r"=", Tok.EQUAL),
        (r":", Tok.COLON),
        (r";", Tok.SEMI_COLON),
        (r",", Tok.COMMA),
        (r"\.", Tok.DOT),
        (r"\|", Tok.PIPE),
        (r"\\", Tok.BACKSLASH),
        (r"\?", Tok.QUESTION_MARK),

        (r"\+", Tok.PLUS),
        (r"\-", Tok.MINUS),
        (r"\*", Tok.TIMES),
        (r"\/", Tok.DIVIDED),
        (r"\:=", Tok.ASSIGN),

        (r">=", Tok.GREATER_OR_EQUAL),
        (r"<=", Tok.LESS_OR_EQUAL),
        (r"<>", Tok.DIAMOND),
        (r"<\*", Tok.LESS_STAR),
        (r">", Tok.GREATER_THAN),
        (r"<", Tok.LESS_THAN),
    ]

    primitives = {
        Tok.KW_REAL: "double",
        Tok.KW_INTEGER: "int",
        Tok.KW_NUMBER: "double",
        Tok.KW_STRING: "std::string",
        Tok.KW_BINARY: "SmallVector<std::byte, 4>",
        Tok.KW_BOOLEAN: "bool",
    }

    parser = Parser(rules, primitives, "ifc.exp")
    parser.parse()
    parser.write_to_file()
