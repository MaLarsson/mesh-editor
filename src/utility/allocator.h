#pragma once

#ifndef UTILITY_ALLOCATOR_H_
#define UTILITY_ALLOCATOR_H_

#include <cstddef>
#include <vector>

class SlabAllocator {
  static constexpr int slab_size = 4096;

public:
  SlabAllocator() = default;

  ~SlabAllocator() {
    for (void* slab : slabs)
      free(slab);
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
    }

    void* ptr = head;
    head += size;

    return ptr;
  }

  template <typename T> T* allocate() { return static_cast<T*>(allocate(sizeof(T))); }

  int memoryUsed() const { return slabs.size() * slab_size; }

private:
  std::vector<void*> slabs;
  std::byte* head = nullptr;
  std::byte* end = nullptr;
};

#endif // UTILITY_ALLOCATOR_H_
