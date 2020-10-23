#include "Factory.h"
#include "classes/Entities.h"

#include <functional>
#include <string_view>
#include <unordered_map>

namespace ifc {

static std::unordered_map<std::string_view, std::function<IfcEntity*(BumpPtrAllocator&)>> factory{
    {"IFCCARTESIANPOINT", [](BumpPtrAllocator& alloc) -> IfcEntity* { return alloc.allocate<IfcCartesianPoint>(); }},
    {"IFCSOMETHING", [](BumpPtrAllocator& alloc) -> IfcEntity* { return nullptr; }}};

IfcEntity* AllocateEntity(std::string_view type, BumpPtrAllocator& alloc) { return factory[type](alloc); }

} // namespace ifc
