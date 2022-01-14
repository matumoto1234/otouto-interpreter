#pragma once

#include "./is-digit.hpp"

#include <algorithm>
#include <string>

// 先頭からis_digitなる文字数
int count_digits(std::string source) {
  auto result_iter = std::find_if_not(source.begin(), source.end(), is_digit);

  return std::distance(source.begin(), result_iter);
}