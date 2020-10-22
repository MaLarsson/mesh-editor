#include "factory.h"
#include "classes/entities.h"

#include <functional>
#include <string_view>
#include <unordered_map>

namespace ifc {

static std::unordered_map<std::string_view, std::function<IfcEntity*(SlabAllocator&)>> factory{
    {"IFCCARTESIANPOINT", [](SlabAllocator& alloc) -> IfcEntity* { return alloc.allocate<IfcCartesianPoint>(); }},
    {"IFCSOMETHING", [](SlabAllocator& alloc) -> IfcEntity* { return nullptr; }}};

IfcEntity* AllocateEntity(std::string_view type, SlabAllocator& alloc) { return factory[type](alloc); }

} // namespace ifc
