#include "Factory.h"
#include "external/Entities.h"

#include <functional>
#include <string_view>
#include <unordered_map>

#define IFC_ALLOCATE_ENTITY(entity_type)                                                           \
  [](BumpPtrAllocator& alloc) -> ifc::IfcEntity {{                                                 \
    return alloc.allocate<ifc::internal::entity_type>();                                           \
  }}

namespace ifc {{

static std::unordered_map<std::string_view, std::function<IfcEntity(BumpPtrAllocator&)>> factory{{{}}};

IfcEntity AllocateEntity(std::string_view type, BumpPtrAllocator& alloc) {{
  return factory[type](alloc);
}}

}} // namespace ifc
