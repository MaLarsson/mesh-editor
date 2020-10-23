#pragma once

#ifndef UTILITY_SMALL_VECTOR_H_
#define UTILITY_SMALL_VECTOR_H_

#include "MemTrackAllocator.h"

#include <vector>

template <typename T, int N = 4>
using SmallVector = std::vector<T, MemTrackAllocator<T>>;

#endif // UTILITY_SMALL_VECTOR_H_
