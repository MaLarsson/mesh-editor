#pragma once

#ifndef UTILITY_THREAD_POOL_H_
#define UTILITY_THREAD_POOL_H_

#include "SmallQueue.h"
#include "SmallVector.h"

#include <condition_variable>
#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <thread>

class ThreadPool {
public:
  ThreadPool(int threads) : m_terminate(false) {
    for (int i = 0; i < threads; ++i) {
      m_workers.emplace_back([this]() {
        for (;;) {
          std::function<void()> task;

          {
            std::unique_lock lock(m_mutex);
            m_condition.wait(lock, [this]() { return m_terminate || !m_tasks.empty(); });

            if (m_terminate && m_tasks.empty()) return;

            task = std::move(m_tasks.pop());
          }

          task();
        }
      });
    }
  }

  ~ThreadPool() {
    {
      std::scoped_lock lock(m_mutex);
      m_terminate = true;
    }

    m_condition.notify_all();

    for (std::thread& worker : m_workers) {
      worker.join();
    }
  }

  template <typename F, typename... Args>
  auto enqueue(F&& f, Args&&... args) {
    auto task = std::make_shared<std::packaged_task<std::invoke_result_t<F, Args...>()>>(
        [f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)]() {
          return std::apply(f, args);
        });

    std::future result = task->get_future();

    {
      std::scoped_lock lock(m_mutex);
      m_tasks.emplace([task]() { (*task)(); });
    }

    m_condition.notify_one();

    return result;
  }

private:
  SmallVector<std::thread, 16> m_workers;
  SmallQueue<std::function<void()>> m_tasks;

  std::mutex m_mutex;
  std::condition_variable m_condition;
  bool m_terminate;
};

#endif // UTILITY_THREAD_POOL_H_
