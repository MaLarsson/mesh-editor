#pragma once

#ifndef IMPORT_IFC_FACTORY_H_
#define IMPORT_IFC_FACTORY_H_

#include "../../utility/BumpPtrAllocator.h"
#include "external/Entities.h"

#include <string_view>

namespace ifc {

IfcEntity AllocateEntity(std::string_view type, BumpPtrAllocator& alloc);

} // namespace ifc

#endif // IMPORT_IFC_FACTORY_H_
