#pragma once

#ifndef IMPORT_IFC_CLASSES_ENTITIES_H_
#define IMPORT_IFC_CLASSES_ENTITIES_H_

#include "../../utility/SmallVector.h"
#include "types.h"

namespace ifc {

struct IfcEntity {};

struct IfcRepresentationItem : IfcEntity {};
struct IfcGeometricRepresentationItem : IfcRepresentationItem {};
struct IfcPoint : IfcGeometricRepresentationItem {};

struct IfcCartesianPoint : IfcPoint {
  SmallVector<IfcLengthMeasure, 3> Coordinates;
};

} // namespace ifc

#endif // IMPORT_IFC_CLASSES_ENTITIES_H_
