#pragma once

#include <string>

template <typename InputType, typename OutputType>
class TestCase {
  std::string m_test_name;
  InputType m_input;
  OutputType m_output;

public:
  TestCase(std::string test_name, InputType input, OutputType output): m_test_name(test_name), m_input(input), m_output(output) {}

  std::string testName() { return m_test_name; }
  InputType input() { return m_input; }
  OutputType output() { return m_output; }
};
