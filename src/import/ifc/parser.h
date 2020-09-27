#pragma once

#ifndef IMPORT_IFC_PARSER_H_
#define IMPORT_IFC_PARSER_H_

#include "classes/entities.h"

#include <memory>
#include <string_view>
#include <vector>

namespace ifc {

class Parser {
 public:
  Parser(std::string_view filename);

 private:
  std::vector<std::unique_ptr<Entity>> entities;
};

} // namespace ifc

#endif // IMPORT_IFC_PARSER_H_
