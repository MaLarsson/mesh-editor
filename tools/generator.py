from pathlib import Path
from enum import Enum
from re import compile as regex_compile


class Tok(Enum):
    KW_TYPE = 1
    KW_END_TYPE = 2
    KW_ENTITY = 3
    KW_END_ENTITY = 4
    KW_SCHEMA = 5
    KW_END_SCHEMA = 6

    KW_WHERE = 7
    KW_FIXED = 8
    KW_OF = 9
    KW_OPTIONAL = 10
    KW_EXISTS = 11

    KW_REAL = 12
    KW_INTEGER = 13
    KW_NUMBER = 14
    KW_STRING = 15
    KW_BINARY = 16
    KW_BOOLEAN = 17
    KW_LOGICAL = 18
    KW_ARRAY = 19
    KW_LIST = 20
    KW_SET = 21
    KW_ENUMERATION = 22
    KW_SELECT = 23

    KW_OR = 24
    KW_AND = 25
    KW_NOT = 26
    KW_SIZEOF = 27
    KW_SELF = 28
    KW_ABSTRACT = 29
    KW_SUBTYPE = 30
    KW_TYPEOF = 31
    KW_QUERY = 32

    NUMBER = 33
    STRING_LITERAL = 34
    COMMENT = 35
    IDENTIFIER = 36

    L_CURLY = 37
    R_CURLY = 38
    L_BRACKET = 39
    R_BRACKET = 40
    L_PAREN = 41
    R_PAREN = 42

    GREATER_THAN = 43
    LESS_THAN = 44
    GREATER_OR_EQUAL = 45
    LESS_OR_EQUAL = 46
    DIAMOND = 47
    LESS_STAR = 48

    PLUS = 49
    MINUS = 50
    TIMES = 51
    DIVIDED = 52

    ASSIGN = 53
    DOT = 54
    PIPE = 55
    BACKSLASH = 56
    COMMA = 57
    WHITESPACE = 58
    EQUAL = 59
    COLON = 60
    SEMI_COLON = 61
    QUESTION_MARK = 62
    UNKNOWN = 63
    EOF = 64


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


class Parser(object):
    def __init__(self, rules, primitives, file_name):
        self.lexer = Lexer(rules, file_name)
        self.primitives = primitives
        self.types = []

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

        if tok.kind in primitives:
            self.types.append("using {} = {};".format(identifier, primitives[tok.kind]))
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
            value_type = primitives[tok.kind] if tok.kind in primitives else tok.value
            self.types.append("using {} = SmallVector<{}, {}>;".format(identifier, value_type, count))
        elif tok.kind == Tok.KW_ENUMERATION:
            assert next(token_generator).kind == Tok.KW_OF
            assert next(token_generator).kind == Tok.L_PAREN

            value_types = []
            for tok in token_generator:
                if tok.kind == Tok.IDENTIFIER:
                    value_types.append(tok.value)
                elif tok.kind == Tok.R_PAREN:
                    break

            self.types.append("enum class {} {{ {} }};".format(identifier, ", ".join(value_types)))
        elif tok.kind == Tok.KW_SELECT:
            assert next(token_generator).kind == Tok.L_PAREN

            value_types = []
            for tok in token_generator:
                if tok.kind == Tok.IDENTIFIER:
                    value_types.append(tok.value)
                elif tok.kind == Tok.R_PAREN:
                    break

            self.types.append("using {} = std::variant<{}>;".format(identifier, ", ".join(value_types)))
        elif tok.kind == Tok.KW_LOGICAL:
            self.types.append("enum class {} {{ TRUE, FALSE, UNKNOWN }};".format(identifier))
        elif tok.kind == Tok.KW_SET:
            assert next(token_generator).kind == Tok.L_BRACKET
            assert next(token_generator).kind == Tok.NUMBER
            assert next(token_generator).kind == Tok.COLON
            next(token_generator)
            assert next(token_generator).kind == Tok.R_BRACKET
            assert next(token_generator).kind == Tok.KW_OF

            tok = next(token_generator)
            value_type = primitives[tok.kind] if tok.kind in primitives else tok.value
            self.types.append("using {} = std::unordered_set<{}>;".format(identifier, value_type))
        elif tok.kind == Tok.IDENTIFIER:
            self.types.append("using {} = {};".format(identifier, tok.value))

    def __parse_entity(self, token_generator):
        tok = next(token_generator)
        assert tok.kind == Tok.IDENTIFIER

        print(tok.value)

        for tok in token_generator:
            if tok.kind == Tok.KW_END_ENTITY:
                break


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
