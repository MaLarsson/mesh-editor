#include "Parser.h"
#include "../../utility/ThreadPool.h"
#include "Factory.h"
#include "Lexer.h"

#include <chrono>
#include <future>
#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) : m_lexer(filename) {}

void Parser::parse() {
  m_lexer.generateTokens();
  m_entities.reserve(m_lexer.m_entity_count * 2); // TODO: test for map with load factor 0.5

  std::cout << "entities: " << m_lexer.m_entity_count << "\n";
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

  ThreadPool pool(4);

  int i = 100;
  SmallVector<std::future<int>> results;

  results.push_back(pool.enqueue([=](int n) { return i + n; }, 10));
  results.push_back(pool.enqueue([=](int n) { return i + n; }, 20));

  for (auto& result : results) {
    std::cout << "thread pool result: " << result.get() << '\n';
  }
}

} // namespace ifc
