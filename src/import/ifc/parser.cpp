#include "parser.h"
#include "entity_factory.h"

#include <iostream>

namespace ifc {

Parser::Parser(std::string_view filename) {
  IfcEntity* entity = AllocateEntity("IFCCARTESIANPOINT");
  entities.push_back(std::unique_ptr<IfcEntity>(entity));

  auto point = static_cast<IfcCartesianPoint*>(entity);
  point->Coordinates.reserve(3);
  point->Coordinates.push_back(0.5);
  point->Coordinates.push_back(0.1);
  point->Coordinates.push_back(0.3);

  std::cout << point->Coordinates[0];
}

} // namespace ifc
