#pragma once

#ifndef IMPORT_IFC_CLASSES_ENTITIES_H_
#define IMPORT_IFC_CLASSES_ENTITIES_H_

#include "types.h"

#include <vector>

namespace ifc {

struct IfcEntity {};

struct IfcRepresentationItem : IfcEntity {};
struct IfcGeometricRepresentationItem : IfcRepresentationItem {};
struct IfcPoint : IfcGeometricRepresentationItem {};

struct IfcCartesianPoint : IfcPoint {
  std::vector<IfcLengthMeasure> Coordinates;
};

} // namespace ifc

#endif // IMPORT_IFC_CLASSES_ENTITIES_H_
