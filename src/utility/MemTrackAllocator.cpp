#ifndef NDEBUG

#include "MemTrackAllocator.h"

#include <cstddef>

static std::size_t current_memory = 0;

std::size_t CurrentMemUsage() { return current_memory; }
void EditMemUsage(std::size_t n) { current_memory += n; }

#endif // NDEBUG
