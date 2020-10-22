#pragma once

#ifndef IMPORT_IFC_FACTORY_H_
#define IMPORT_IFC_FACTORY_H_

#include "../../utility/allocator.h"
#include "classes/entities.h"

#include <string_view>

namespace ifc {

IfcEntity* AllocateEntity(std::string_view type, SlabAllocator& alloc);

} // namespace ifc

#endif // IMPORT_IFC_FACTORY_H_
