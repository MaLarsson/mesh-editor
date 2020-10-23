#pragma once

#ifndef UTILITY_MEM_TRACK_ALLOCATOR_H_
#define UTILITY_MEM_TRACK_ALLOCATOR_H_

#include <cstddef>
#include <memory>

#ifdef NDEBUG

template <typename T>
using MemTrackAllocator = std::allocator<T>;

#define DEBUG_PRINT_CURRENT_MEM_USAGE_BYTES()
#define DEBUG_PRINT_CURRENT_MEM_USAGE_MB()
#define DEBUG_PRINT_CURRENT_MEM_USAGE_GB()

#define DEBUG_ADD_MEM_USAGE(n)
#define DEBUG_REMOVE_MEM_USAGE(n)

#else // NDEBUG

template <typename T>
struct MemTrackAllocator {
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;

  MemTrackAllocator() = default;

  template <typename U>
  MemTrackAllocator(const MemTrackAllocator<U> other) {}

  static T* allocate(std::size_t n) {
    AddMemUsage(n * sizeof(T));
    return std::allocator_traits<std::allocator<T>>::allocate(std::allocator<T>{}, n);
  }

  void deallocate(T* mem, std::size_t n) {
    RemoveMemUsage(n * sizeof(T));
    std::allocator_traits<std::allocator<T>>::deallocate(std::allocator<T>{}, mem, n);
  }

  template <typename U>
  struct rebind { using other = MemTrackAllocator<U>; };
};

std::size_t CurrentMemUsage();

void AddMemUsage(std::size_t n);
void RemoveMemUsage(std::size_t n);

#define DEBUG_PRINT_CURRENT_MEM_USAGE_(n, x)                                                                           \
  std::cout << "current mem usage: " << static_cast<double>(CurrentMemUsage()) / n << x

#define DEBUG_PRINT_CURRENT_MEM_USAGE_BYTES() DEBUG_PRINT_CURRENT_MEM_USAGE_(1, "[bytes]\n")
#define DEBUG_PRINT_CURRENT_MEM_USAGE_MB() DEBUG_PRINT_CURRENT_MEM_USAGE_(1'000'000, "[MB]\n")
#define DEBUG_PRINT_CURRENT_MEM_USAGE_GB() DEBUG_PRINT_CURRENT_MEM_USAGE_(1'000'000'000, "[GB]\n")

#define DEBUG_ADD_MEM_USAGE(n) AddMemUsage(n)
#define DEBUG_REMOVE_MEM_USAGE(n) RemoveMemUsage(n)

#endif // NDEBUG

#endif // UTILITY_MEM_TRACK_ALLOCATOR_H_
