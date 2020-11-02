from pathlib import Path
from enum import Enum
from re import compile as regex_compile


class Tok(Enum):
    KW_TYPE = 1
    KW_END_TYPE = 2
    KW_SCHEMA = 33
    KW_WHERE = 34
    KW_FIXED = 40
    KW_OF = 41
    #KW_OPTIONAL
    #KW_EXISTS

    KW_REAL = 50
    KW_INTEGER = 51
    KW_NUMBER = 52
    KW_BINARY = 53
    KW_BOOLEAN = 54
    KW_LOGICAL = 55
    KW_ARRAY = 56
    KW_LIST = 57
    KW_SET = 58
    KW_ENUMERATION = 59
    KW_SELECT = 60

    KW_OR = 35
    KW_AND = 36
    #KW_NOT
    KW_SIZEOF = 37
    KW_SELF = 38
    #KW_TYPEOF
    #KW_QUERY

    NUMBER = 10
    STRING_LITERAL = 13
    COMMENT = 3
    IDENTIFIER = 4

    L_CURLY = 24
    R_CURLY = 25
    L_BRACKET = 20
    R_BRACKET = 21
    L_PAREN = 22
    R_PAREN = 23

    GREATER_THAN = 15
    LESS_THAN = 16
    GREATER_OR_EQUAL = 17
    LESS_OR_EQUAL = 18
    #<>
    #<*

    #:=
    #*
    DOT = 19
    PIPE = 28
    BACKSLASH = 29
    COMMA = 14
    WHITESPACE = 5
    EQUAL = 6
    COLON = 7
    SEMI_COLON = 8
    QUESTION_MARK = 31
    UNKNOWN = 32
    EOF = 9


class Token(object):
    def __init__(self, kind, value):
        self.kind = kind
        self.value = value


class Lexer(object):
    def __init__(self, rules, skip_whitespace=True):
        idx = 1
        regex_parts = []
        self.group_kind = {}

        for regex, kind in rules:
            groupname = "GROUP%s" % idx
            regex_parts.append("(?P<%s>%s)" % (groupname, regex))
            self.group_kind[groupname] = kind
            idx += 1

        self.regex = regex_compile("|".join(regex_parts))
        self.skip_whitespace = skip_whitespace
        self.re_ws_skip = regex_compile("\S")

    def input(self, file_name):
        self.buf = Path(file_name).read_text()
        self.pos = 0

    def token(self):
        if self.pos >= len(self.buf):
            return None

        if self.skip_whitespace:
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

    def tokens(self):
        while 1:
            tok = self.token()
            if tok is None: break
            yield tok
            if tok.kind == Tok.UNKNOWN: break


if __name__ == "__main__":
    rules = [
        (r"TYPE", Tok.KW_TYPE),
        (r"END_TYPE", Tok.KW_END_TYPE),
        (r"SCHEMA", Tok.KW_SCHEMA),
        (r"WHERE", Tok.KW_WHERE),
        (r"FIXED", Tok.KW_FIXED),
        (r"OF", Tok.KW_OF),

        (r"REAL", Tok.KW_REAL),
        (r"INTEGER", Tok.KW_INTEGER),
        (r"NUMBER", Tok.KW_NUMBER),
        (r"BINARY", Tok.KW_BINARY),
        (r"BOOLEAN", Tok.KW_BOOLEAN),
        (r"LOGICAL", Tok.KW_LOGICAL),
        (r"ARRAY", Tok.KW_ARRAY),
        (r"LIST", Tok.KW_LIST),
        (r"SET", Tok.KW_SET),
        (r"ENUMERATION", Tok.KW_ENUMERATION),
        (r"SELECT", Tok.KW_SELECT),

        (r"OR", Tok.KW_OR),
        (r"AND", Tok.KW_AND),

        (r"SIZEOF", Tok.KW_SIZEOF),
        (r"SELF", Tok.KW_SELF),

        (r"\(\*[\s\S]+?\*\)", Tok.COMMENT),
        (r"\'[\s\S]+?\'", Tok.STRING_LITERAL),
        (r"\d+(\.\d*)?", Tok.NUMBER),
        (r"[a-zA-Z_]\w+", Tok.IDENTIFIER),

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

        (r">=", Tok.GREATER_OR_EQUAL),
        (r"<=", Tok.LESS_OR_EQUAL),
        (r">", Tok.GREATER_THAN),
        (r"<", Tok.LESS_THAN),
    ]

    lexer = Lexer(rules)
    lexer.input("ifc.exp")

    for tok in lexer.tokens():
        print(tok.kind, tok.value)
        #if tok.kind == Tok.KW_TYPE:
            #print(tok.kind)
        #print(tok.kind, tok.value)


    #regex = regex_compile("\d+[.,]?\d*");
    #match = regex.match("0.; dmsamdksmdkas")
    #print(match)
