#pragma once

#ifndef IMPORT_IFC_TOKEN_H_
#define IMPORT_IFC_TOKEN_H_

#include <string_view>

namespace ifc::tok {

enum TokenKind {
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_EQUAL,

  TOKEN_EOF,
  TOKEN_ENTITY,
  TOKEN_IDENTIFIER,

  TOKEN_KW_HEADER,
  TOKEN_KW_ENDSEC,
  TOKEN_KW_DATA,

  TOKEN_UNKNOWN
};

struct Token {
  TokenKind kind;

  int line;
  int column;

  union {
    int number;
    std::string_view string;
 } value{0};
};

} // namespace ifc::tok

#endif // IMPORT_IFC_TOKEN_H_
