#pragma once

#ifndef IMPORT_IFC_LEXER_H_
#define IMPORT_IFC_LEXER_H_

#include "../../utility/SmallVector.h"
#include "Token.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string_view>

namespace ifc {

class Lexer {
public:
  Lexer(std::string_view filename)
      : file(nullptr), pos(0), file_size(0), m_tokens{}, m_token_index(0) {
    // m_tokens.reserve(70000000); // TODO, something smart ...

    if (FILE* file_handle = fopen(filename.data(), "rb")) {
      std::cout << "opened file\n";

      fseek(file_handle, 0, SEEK_END);
      file_size = ftell(file_handle);
      rewind(file_handle);

      file = static_cast<char*>(malloc(file_size));
      DEBUG_ADD_MEM_USAGE(file_size);

      fread(file, 1, file_size, file_handle);
      fclose(file_handle);
    }
  }

  ~Lexer() {
    free(file);
    DEBUG_REMOVE_MEM_USAGE(file_size);
  }

  void generateTokens() {
    if (!file)
      return;

    // parseToken();
    parseToken2();

    while (m_tokens.back().kind != tok::TOKEN_EOF) {
      if (m_tokens.back().kind == tok::TOKEN_ENTITY)
        ++entity_count;

      // parseToken();
      parseToken2();
    }
  }

  void parseToken2() {
    tok::Token tok;
    eatWhitespace();

    if (pos == file_size) {
      tok.kind = tok::TOKEN_EOF;
      m_tokens.push_back(tok);
      return;
    }

    switch (file[pos++]) {
    case '(':
      tok.kind = tok::TOKEN_ARGUMENTS;
      tok.value.string = parseArguments();
      break;
    case '#':
      tok.kind = tok::TOKEN_IDENTIFIER;
      tok.value.number = parseInteger();
      break;
    case 'I':
      if (file[pos] == 'F' && file[pos + 1] == 'C') {
        tok.kind = tok::TOKEN_ENTITY;
        tok.value.string = parseEntityString();
      }
      break;
    }

    m_tokens.push_back(tok);
  }

  std::string_view parseArguments() {
    char* start = &file[pos];
    size_t length = 0;
    int level = 1;

    for (; pos != file_size; ++pos) {
      switch (file[pos]) {
      case ')':
        --level;
        break;
      case '(':
        ++level;
        [[fallthrough]];
      default:
        ++length;
      }

      if (level == 0)
        break;
    }

    return {start, length};
  }

  // Parses the next token and append it to the list of tokens and return the next token in the
  // token stream. Note that calling this method when the previous token was of the token TOKEN_EOF
  // is undefined behaviour.
  tok::Token* getNextToken() {
    if (m_token_index == m_tokens.size())
      parseToken();

    return &m_tokens[m_token_index++];
  }

  // Will do the same thing as getNextToken but will not advance the token index.
  tok::Token* peekNextToken() {
    if (m_token_index == m_tokens.size())
      parseToken();

    return &m_tokens[m_token_index];
  }

  // Returns the previous token in the token stream.
  tok::Token* getPrevToken() { return &m_tokens[m_token_index - 2]; }

  // Parses a token out from the source file.
  // IF we're already at the end of the file a token of the kind TOKEN_EOF will be added to the
  // token stream.
  void parseToken() {
    tok::Token tok;
    eatWhitespace();

    if (pos == file_size) {
      tok.kind = tok::TOKEN_EOF;
      m_tokens.push_back(tok);
      return;
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
        Number num = parseNumber();
        if (num.is_floating_point) {
          tok.kind = tok::TOKEN_FLOAT_LITERAL;
          tok.value.floating_point = num.value;
        } else {
          tok.kind = tok::TOKEN_INT_LITERAL;
          tok.value.number = static_cast<int>(num.value);
        }
      } else {
        tok.kind = tok::TOKEN_UNKNOWN;
      }
      break;
    }

    m_tokens.push_back(tok);
  }

  // Advance the position in the source file until the beginning of the next token.
  void eatWhitespace() {
    for (; pos != file_size && isspace(file[pos]); ++pos) {
    }
  }

  // Parse an integer out of the source file.
  int parseInteger() {
    int number = 0;

    for (; pos != file_size && isdigit(file[pos]); ++pos) {
      number *= 10;
      number += (file[pos] - '0');
    }

    return number;
  }

  // Representation of a number parsed from the source file.
  // If the value has any decimals in the source file i.e. `0.0` the is_floating_point flag will be
  // set.
  struct Number {
    double value;
    bool is_floating_point;
  };

  // Parse a number out of the source file.
  // Can be either an integer of a floating point number.
  Number parseNumber() {
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

    return {number, decimal};
  }

  // Parse a string out the the source file.
  // Returns a pointer pair pointing the the start and end of the string in the source file.
  std::string_view parseEntityString() {
    char* start = &file[pos - 1];
    typename std::string_view::size_type identifier_length = 1;

    for (; isalnum(file[pos]); ++pos)
      ++identifier_length;

    return {start, identifier_length};
  }

  void reset() { m_token_index = 0; }

  int getEntityCount() const { return entity_count; }

public:
  char* file;
  int pos;
  int file_size;

  SmallVector<tok::Token> m_tokens;
  int m_token_index = 0;
  int entity_count = 0;
};

} // namespace ifc

#endif // IMPORT_IFC_LEXER_H_
