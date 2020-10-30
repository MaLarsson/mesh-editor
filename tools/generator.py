from pathlib import Path
from enum import Enum


class Tok(Enum):
    KEYWORD_TYPE = 1
    KEYWORD_END_TYPE = 2

    COMMENT = 3
    ENTITY = 4

    EQUAL = 5
    COLON = 6
    EOF = 7


class Token(object):
    def __init__(self, kind, value=None):
        self.kind = kind
        self.value = value


class Lexer(object):
    def __init__(self, file_path):
        self.data = Path(file_path).read_text()
        self.tokens = []

    def generate_tokens(self):
        self.tokens.append(Token(Tok.KEYWORD_TYPE))
        self.tokens.append(Token(Tok.ENTITY, "IfcAbsorbedDoseMeasure"))
        self.tokens.append(Token(Tok.EQUAL))
        self.tokens.append(Tok.EOF)

    def print_token(self, index):
        tok = self.tokens[index]
        print(tok.kind, tok.value)


if __name__ == "__main__":
    lexer = Lexer("ifc.exp")
    lexer.generate_tokens()

    # print tokens
    lexer.print_token(0)
    lexer.print_token(1)
