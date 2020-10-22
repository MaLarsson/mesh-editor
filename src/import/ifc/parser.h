#pragma once

#ifndef IMPORT_IFC_PARSER_H_
#define IMPORT_IFC_PARSER_H_

#include "../../utility/allocator.h"
#include "classes/entities.h"
#include "lexer.h"

#include <memory>
#include <string_view>
#include <vector>

namespace ifc {

class Parser {
public:
  Parser(std::string_view filename);

  void parse();

private:
  SlabAllocator m_alloc;
  Lexer m_lexer;
  std::vector<IfcEntity*> m_entities;
};

} // namespace ifc

#endif // IMPORT_IFC_PARSER_H_
