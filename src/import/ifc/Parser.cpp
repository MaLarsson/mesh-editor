#include "Parser.h"
#include "Factory.h"
#include "Lexer.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) : m_lexer(filename) {}

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
      IfcEntity* entity = AllocateEntity("IFCCARTESIANPOINT", m_alloc); // TODO
      m_entities.push_back(entity);

      // m_entities.insert(id, AllocateEntity(tok.value.string, m_alloc));
    }
  }
}

} // namespace ifc
