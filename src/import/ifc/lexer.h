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
  Lexer(std::string_view filename) : pos(0) {
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

    if (pos == file_size) {
      tok.kind = tok::TOKEN_EOF;
      return tok;
    }

    switch (file[pos]) {
    case '(':
      tok.kind = tok::TOKEN_LPAREN;
      break;
    case ')':
      tok.kind = tok::TOKEN_RPAREN;
      break;
    case '=':
      tok.kind = tok::TOKEN_EQUAL;
      break;
    case '#':
      tok.kind = tok::TOKEN_IDENTIFIER;
      tok.value.number = 0;
      while (isdigit(file[++pos])) {
        tok.value.number *= 10;
        tok.value.number += (file[pos] - '0');
      }
      --pos;
      break;
    case 'I':
      if (file[pos + 1] == 'F' && file[pos + 2] == 'C') {
        tok.kind = tok::TOKEN_ENTITY;
        char* start = &file[pos];
        int identifier_length = 1;
        while (isalpha(file[++pos]))
          ++identifier_length;
        --pos;
        tok.value.string = std::string_view(start, identifier_length);
      }
      break;
    default:
      tok.kind = tok::TOKEN_UNKNOWN;
      break;
    }

    ++pos;

    return tok;
  }

private:
  char* file;
  int pos;
  int file_size;
};

} // namespace ifc

#endif // IMPORT_IFC_LEXER_H_
