#pragma once

#include <chrono>

struct Stopwatch {
  std::chrono::high_resolution_clock::time_point start;

  Stopwatch() { restart(); }

  void restart() { start = std::chrono::high_resolution_clock::now(); }

  std::chrono::milliseconds::rep elapsed() {
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  }
};