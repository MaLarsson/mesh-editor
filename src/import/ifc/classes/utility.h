#pragma once

#ifndef IMPORT_IFC_CLASSES_UTILITY_H_
#define IMPORT_IFC_CLASSES_UTILITY_H_

namespace ifc {

// LIST [1:2] OF T;
template <typename T> struct Vec2 { T x, y; };

// LIST [1:3] OF T;
template <typename T> struct Vec3 { T x, y, z; };

} // namespace ifc

#endif // IMPORT_IFC_CLASSES_UTILITY_H_
