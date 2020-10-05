#pragma once

#ifndef IMPORT_IFC_LEXER_H_
#define IMPORT_IFC_LEXER_H_

#include "token.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string_view>

namespace ifc {

class Lexer {
public:
  Lexer(std::string_view filename) : file(nullptr), pos(0), file_size(0) {
    FILE* file_handle = fopen(filename.data(), "rb");

    if (file_handle) {
      std::cout << "opened file\n";

      fseek(file_handle, 0, SEEK_END);
      file_size = ftell(file_handle);
      fseek(file_handle, 0, SEEK_SET);

      file = (char*)malloc(file_size);
      fread(file, 1, file_size, file_handle);

      fclose(file_handle);
    }
  }

  tok::Token getNextToken() {
    tok::Token tok;
    eatWhitespace();

    if (pos == file_size) {
      tok.kind = tok::TOKEN_EOF;
      return tok;
    }

    switch (file[pos++]) {
    case '(':
      tok.kind = tok::TOKEN_LPAREN;
      break;
    case ')':
      tok.kind = tok::TOKEN_RPAREN;
      break;
    case '=':
      tok.kind = tok::TOKEN_EQUAL;
      break;
    case ',':
      tok.kind = tok::TOKEN_COMMA;
      break;
    case ';':
      tok.kind = tok::TOKEN_SEMICOLON;
      break;
    case '$':
      tok.kind = tok::TOKEN_NULL;
      break;
    case '#':
      if (!isdigit(file[pos])) {
        tok.kind = tok::TOKEN_ERROR;
      } else {
        tok.kind = tok::TOKEN_IDENTIFIER;
        tok.value.number = parseInteger();
      }
      break;
    case 'I':
      if (file[pos] == 'F' && file[pos + 1] == 'C') {
        tok.kind = tok::TOKEN_ENTITY;
        tok.value.string = parseEntityString();
      }
      break;
    default:
      if (isdigit(file[pos - 1])) {
        tok.kind = tok::TOKEN_FLOAT_LITERAL;
        tok.value.floating_point = parseNumber();
      } else {
        tok.kind = tok::TOKEN_UNKNOWN;
      }
      break;
    }

    return tok;
  }

  void eatWhitespace() {
    for (; isspace(file[pos]); ++pos) {
      if (pos == file_size)
        return;
    }
  }

  int parseInteger() {
    int number = 0;

    for (; isdigit(file[pos]); ++pos) {
      number *= 10;
      number += (file[pos] - '0');
    }

    return number;
  }

  double parseNumber() {
    double number = 0;
    bool decimal = false;
    double decimal_divider = 10;

    // TODO: ugh... deal with the pos problem...
    for (; isdigit(file[pos - 1]) || file[pos - 1] == '.'; ++pos) {
      if (file[pos - 1] == '.') {
        decimal = true;
      } else if (decimal) {
        double dec = (file[pos - 1] - '0') / decimal_divider;
        decimal_divider *= 10;
        number += dec;
      } else {
        number *= 10;
        number += (file[pos - 1] - '0');
      }
    }

    --pos;

    return number;
  }

  std::string_view parseEntityString() {
    char* start = &file[pos - 1];
    typename std::string_view::size_type identifier_length = 1;
    for (; isalpha(file[pos]); ++pos)
      ++identifier_length;

    return {start, identifier_length};
  }

private:
  char* file;
  int pos;
  int file_size;
};

} // namespace ifc

#endif // IMPORT_IFC_LEXER_H_
