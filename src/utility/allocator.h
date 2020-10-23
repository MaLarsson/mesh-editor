#pragma once

#ifndef UTILITY_ALLOCATOR_H_
#define UTILITY_ALLOCATOR_H_

#include "MemTrackAllocator.h"
#include "small_vector.h"

#include <cstddef>

class SlabAllocator {
  static constexpr int slab_size = 4096;

public:
  SlabAllocator() = default;

  ~SlabAllocator() {
    for (void* slab : slabs) {
      free(slab);
      DEBUG_EDIT_MEM_USAGE(-slab_size);
    }
  }

  SlabAllocator(const SlabAllocator&) = delete;
  SlabAllocator(SlabAllocator&&) = delete;
  SlabAllocator& operator=(const SlabAllocator&) = delete;
  SlabAllocator& operator=(SlabAllocator&&) = delete;

  void* allocate(int size) {
    if (size >= (end - head)) {
      head = static_cast<std::byte*>(malloc(slab_size));
      end = head + slab_size;
      slabs.push_back(head);
      DEBUG_EDIT_MEM_USAGE(slab_size);
    }

    void* ptr = head;
    head += size;

    return ptr;
  }

  template <typename T> T* allocate() { return static_cast<T*>(allocate(sizeof(T))); }

private:
  SmallVector<void*> slabs;
  std::byte* head = nullptr;
  std::byte* end = nullptr;
};

#endif // UTILITY_ALLOCATOR_H_
