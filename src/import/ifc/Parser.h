#pragma once

#ifndef IMPORT_IFC_PARSER_H_
#define IMPORT_IFC_PARSER_H_

#include "../../utility/BumpPtrAllocator.h"
#include "../../utility/SmallVector.h"
#include "classes/Entities.h"
#include "Lexer.h"

#include <memory>
#include <string_view>

namespace ifc {

class Parser {
public:
  Parser(std::string_view filename);

  void parse();

private:
  BumpPtrAllocator m_alloc;
  Lexer m_lexer;
  SmallVector<IfcEntity*, 0> m_entities;
};

} // namespace ifc

#endif // IMPORT_IFC_PARSER_H_
