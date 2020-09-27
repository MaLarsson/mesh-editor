#include "entity_factory.h"
#include "classes/entities.h"

#include <functional>
#include <string_view>
#include <unordered_map>

namespace ifc {

static std::unordered_map<std::string_view, std::function<IfcEntity* (void)>>
    factory = {
        {"IFCCARTESIANPOINT", []() -> IfcEntity* { return new IfcCartesianPoint; }},
        {"IFCSOMETHING", []() -> IfcEntity* { return nullptr; }}};

IfcEntity* AllocateEntity(std::string_view type) { return factory[type](); }

} // namespace ifc
