#include "parser.h"
#include "entity_factory.h"
#include "lexer.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) {
  Lexer lexer(filename);
  Token tok = lexer.getNextToken();

  int id = -1;

  while (tok.type != TOKEN_EOF) {
    Token next_token = lexer.getNextToken();

    if (tok.type == TOKEN_IDENT && next_token.type == TOKEN_EQUAL) {
      // std::cout << tok.value.number << '\n';
      id = tok.value.number;
    } else if (tok.type == TOKEN_TYPE) {
      if (tok.value.string == "IFCCARTESIANPOINT") {
        // std::cout << id << ": " << tok.value.string << '\n';

        IfcEntity* entity = AllocateEntity(tok.value.string);
        entities.push_back(std::unique_ptr<IfcEntity>(entity));
      }
    }

    tok = next_token;
  }
}

} // namespace ifc
