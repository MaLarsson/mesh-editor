#include "parser.h"
#include "entity_factory.h"
#include "lexer.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) {
  Lexer lexer(filename);
  tok::Token tok = lexer.getNextToken();

  int id = -1;

  while (tok.kind != tok::TOKEN_EOF) {
    tok::Token next_token = lexer.getNextToken();

    if (tok.kind == tok::TOKEN_IDENTIFIER && next_token.kind == tok::TOKEN_EQUAL) {
      id = tok.value.number;
    } else if (tok.kind == tok::TOKEN_ENTITY) {
      // TODO: do this for all entities, not just cartesion points
      if (tok.value.string == "IFCCARTESIANPOINT") {

        // TODO: set the size in the begining, dont keep increasing like this
        if (entities.size() < id) {
          entities.resize(id);
        }

        IfcEntity* entity = AllocateEntity(tok.value.string);
        entities[id - 1] = std::unique_ptr<IfcEntity>(entity);
      }
    }

    tok = next_token;
  }

  for (auto&& entity : entities) {
    if (entity.get() != nullptr) {
      // std::cout << "certesian point!\n";
    }
  }
}

} // namespace ifc
