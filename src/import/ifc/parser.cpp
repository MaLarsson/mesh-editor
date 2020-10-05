#include "parser.h"
#include "entity_factory.h"
#include "lexer.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) {
  Lexer lexer(filename);
  tok::Token tok = lexer.getNextToken();

  int id = -1;
  tok::Token prev_token;

  while (tok.kind != tok::TOKEN_EOF) {
    // std::cout << tok.kind << '\n';
    tok::Token next_token = lexer.getNextToken();

    if (tok.kind == tok::TOKEN_IDENTIFIER && next_token.kind == tok::TOKEN_EQUAL) {
      id = tok.value.number;
    } else if (tok.kind == tok::TOKEN_INT_LITERAL) {
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
}

} // namespace ifc
