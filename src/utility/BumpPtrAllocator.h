#pragma once

#ifndef UTILITY_BUMP_PTR_ALLOCATOR_H_
#define UTILITY_BUMP_PTR_ALLOCATOR_H_

#include "MemTrackAllocator.h"
#include "SmallVector.h"

#include <cstddef>

class BumpPtrAllocator {
  static constexpr int slab_size = 4096;

public:
  BumpPtrAllocator() = default;

  ~BumpPtrAllocator() {
    for (void* slab : slabs) {
      free(slab);
      DEBUG_REMOVE_MEM_USAGE(slab_size);
    }
  }

  BumpPtrAllocator(const BumpPtrAllocator&) = delete;
  BumpPtrAllocator(BumpPtrAllocator&&) = delete;
  BumpPtrAllocator& operator=(const BumpPtrAllocator&) = delete;
  BumpPtrAllocator& operator=(BumpPtrAllocator&&) = delete;

  void* allocate(int size) {
    if (size >= (end - head)) {
      head = static_cast<std::byte*>(malloc(slab_size));
      end = head + slab_size;
      slabs.push_back(head);
      DEBUG_ADD_MEM_USAGE(slab_size);
    }

    void* ptr = head;
    head += size;

    return ptr;
  }

  template <typename T>
  T* allocate() {
    return static_cast<T*>(allocate(sizeof(T)));
  }

private:
  SmallVector<void*> slabs;
  std::byte* head = nullptr;
  std::byte* end = nullptr;
};

#endif // UTILITY_BUMP_PTR_ALLOCATOR_H_
