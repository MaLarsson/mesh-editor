#pragma once

#ifndef IMPORT_IFC_CLASSES_ENTITIES_H_
#define IMPORT_IFC_CLASSES_ENTITIES_H_

#include "types.h"
#include "utility.h"

namespace ifc {

struct Entity {};

struct RepresentationItem : Entity {};
struct GeometricRepresentationItem : RepresentationItem {};
struct Point : GeometricRepresentationItem {};

struct CartesianPoint : Point {
  Vec3<LengthMeasure> Coordinates;
};

} // namespace ifc

#endif // IMPORT_IFC_CLASSES_ENTITIES_H_
