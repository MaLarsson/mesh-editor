#include "Parser.h"
#include "Factory.h"
#include "Lexer.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) : m_lexer(filename) {

  /*
  tok::Token tok = lexer.getNextToken();

  int id = -1;
  int argument_pos = 0;
  tok::Token prev_token;

  while (tok.kind != tok::TOKEN_EOF) {
    tok::Token next_token = lexer.getNextToken();

    if (tok.kind == tok::TOKEN_IDENTIFIER && next_token.kind == tok::TOKEN_EQUAL) {
      id = tok.value.number;
    } else if (tok.kind == tok::TOKEN_COMMA) {
      ++argument_pos;
    } else if (tok.kind == tok::TOKEN_INT_LITERAL) {
      auto entity = entities[id];
      using type = meta::element_type<IfcCartesianPoint, 0>::type;

      // std::cout << "int: " << tok.value.number << '\n';
    } else if (tok.kind == tok::TOKEN_FLOAT_LITERAL) {
      // std::cout << "float: " << tok.value.floating_point << '\n';
    } else if (tok.kind == tok::TOKEN_ENTITY && prev_token.kind == tok::TOKEN_EQUAL) {
      // std::cout << tok.value.string << '\n';

      // TODO: do this for all entities, not just cartesion points
      // if (tok.value.string == "IFCCARTESIANPOINT") {

      // TODO: set the size in the begining, dont keep increasing like this
      if (entities.size() < id) {
        entities.resize(id);
      }

      // IfcEntity* entity = AllocateEntity(tok.value.string);
      IfcEntity* entity = AllocateEntity("IFCCARTESIANPOINT");
      entities[id - 1] = std::unique_ptr<IfcEntity>(entity);
    } else if (tok.kind == tok::TOKEN_ERROR) {
      std::cout << "ERROR!\n";
    }

    prev_token = tok;
    tok = next_token;
  }
  */
}

void Parser::parse() {
  m_lexer.generateTokens();
  m_entities.reserve(m_lexer.entity_count * 2); // TODO: test for map with load factor 0.5

  std::cout << "entities: " << m_lexer.entity_count << "\n";
  std::cout << "tokens: " << m_lexer.m_tokens.size() << "\n";

  int id = -1;

  for (const tok::Token& tok : m_lexer.m_tokens) {
    if (tok.kind == tok::TOKEN_IDENTIFIER) {
      id = tok.value.number;
    } else if (tok.kind == tok::TOKEN_ENTITY) {
      IfcEntity* entity = AllocateEntity("IFCCARTESIANPOINT", m_alloc);
      m_entities.push_back(entity);
    }
  }
}

} // namespace ifc
