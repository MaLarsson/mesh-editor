#pragma once

#ifndef UTILITY_SMALL_QUEUE_H_
#define UTILITY_SMALL_QUEUE_H_

#include "SmallVector.h"

#include <utility>

template <typename T, int N = 4>
class SmallQueue {
public:
  T& pop() { return m_data[m_index++]; }
  bool empty() const { return m_index >= m_data.size(); }

  template <typename... Args>
  T& emplace(Args&&... args) {
    return m_data.emplace_back(std::forward<Args>(args)...);
  }

private:
  SmallVector<T, N> m_data;
  int m_index = 0;
};

#endif // UTILITY_SMALL_QUEUE_H_
