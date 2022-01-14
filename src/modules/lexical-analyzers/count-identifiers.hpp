#pragma once

#include "./is-identifier.hpp"

#include <string>


// is_identifierなる先頭からの文字数
int count_identifiers(std::string source){
  auto result_iter = std::find_if_not(source.begin(), source.end(), is_identifier);

  return std::distance(source.begin(), result_iter);
}