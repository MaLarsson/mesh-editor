#include "Factory.h"
#include "classes/Entities.h"

#include <functional>
#include <string_view>
#include <unordered_map>

#define IFC_ALLOCATE_ENTITY(entity_type)                                                           \
  [](BumpPtrAllocator& alloc) -> IfcEntity* { return alloc.allocate<entity_type>(); }

namespace ifc {

static std::unordered_map<std::string_view, std::function<IfcEntity*(BumpPtrAllocator&)>> factory{
    {"IFCCARTESIANPOINT", IFC_ALLOCATE_ENTITY(IfcCartesianPoint)}};

IfcEntity* AllocateEntity(std::string_view type, BumpPtrAllocator& alloc) {
  return factory[type](alloc);
}

} // namespace ifc
