#pragma once

#ifndef IMPORT_IFC_ENTITY_FACTORY_H_
#define IMPORT_IFC_ENTITY_FACTORY_H_

#include "classes/entities.h"

#include <string_view>

namespace ifc {

IfcEntity* AllocateEntity(std::string_view type);

} // namespace ifc

#endif // IMPORT_IFC_ENTITY_FACTORY_H_
