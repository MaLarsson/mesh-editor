#pragma once

#ifndef UTILITY_BUMP_PTR_ALLOCATOR_H_
#define UTILITY_BUMP_PTR_ALLOCATOR_H_

#include "MemTrackAllocator.h"
#include "SmallVector.h"

#include <cstddef>

class BumpPtrAllocator {
  static constexpr int slab_size = 4096;

public:
  BumpPtrAllocator() : m_head(nullptr), m_end(nullptr) {}

  ~BumpPtrAllocator() {
    for (void* slab : m_slabs) {
      free(slab);
      DEBUG_REMOVE_MEM_USAGE(slab_size);
    }
  }

  BumpPtrAllocator(const BumpPtrAllocator&) = delete;
  BumpPtrAllocator(BumpPtrAllocator&&) = delete;
  BumpPtrAllocator& operator=(const BumpPtrAllocator&) = delete;
  BumpPtrAllocator& operator=(BumpPtrAllocator&&) = delete;

  void* allocate(int size) {
    if (size >= (m_end - m_head)) {
      m_head = static_cast<std::byte*>(malloc(slab_size));
      m_end = m_head + slab_size;
      m_slabs.push_back(m_head);
      DEBUG_ADD_MEM_USAGE(slab_size);
    }

    void* ptr = m_head;
    m_head += size;

    return ptr;
  }

  template <typename T>
  T* allocate() {
    return static_cast<T*>(allocate(sizeof(T)));
  }

private:
  SmallVector<void*> m_slabs;
  std::byte* m_head;
  std::byte* m_end;
};

#endif // UTILITY_BUMP_PTR_ALLOCATOR_H_
