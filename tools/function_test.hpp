#pragma once

#include "./stopwatch.hpp"
#include "./test_case.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

template <typename InputType, typename OutputType, typename FuncType>
void function_test(std::vector<TestCase<InputType, OutputType>> test_cases, FuncType func) {
  double total_time_s = 0.0;
  int passed_count = 0, failed_count = 0;

  std::cout << std::fixed << std::setprecision(3);

  for (TestCase<InputType, OutputType> test_case: test_cases) {
    Stopwatch stopwatch;

    OutputType output = func(test_case.input());

    double time_s = stopwatch.elapsed() / 1000.0;

    OutputType expected = test_case.output();

    bool is_expected = (output == expected);

    std::cout << (is_expected ? "✓" : "✘") << " ";
    std::cout << test_case.output() << "(" << time_s << "[s])\n";

    total_time_s += time_s;
    if (is_expected)
      passed_count++;
    else
      failed_count++;
  }

  std::cout << "\n";
  std::cout << std::setw(10) << "Passed:" << passed_count << std::setw(10) << "Failed:" << failed_count << "\n";
  std::cout << std::setw(10) << "Time:" << total_time_s << "[s]\n";
}
