#pragma once

#ifndef IMPORT_IFC_TOKEN_H_
#define IMPORT_IFC_TOKEN_H_

#include <string_view>

namespace ifc::tok {

enum TokenKind {
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_EQUAL,
  TOKEN_COMMA,
  TOKEN_SEMICOLON,

  TOKEN_NULL,
  TOKEN_ENTITY,
  TOKEN_IDENTIFIER,
  TOKEN_STRING_LITERAL,
  TOKEN_INT_LITERAL,
  TOKEN_FLOAT_LITERAL,

  TOKEN_ARGUMENTS,

  TOKEN_KW_HEADER,
  TOKEN_KW_ENDSEC,
  TOKEN_KW_DATA,

  TOKEN_ERROR,
  TOKEN_UNKNOWN,
  TOKEN_EOF
};

struct Token {
  TokenKind kind;

  union {
    int number;
    double floating_point;
    std::string_view string;
  } value{0};
};

} // namespace ifc::tok

#endif // IMPORT_IFC_TOKEN_H_
