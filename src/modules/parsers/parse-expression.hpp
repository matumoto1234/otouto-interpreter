#pragma once

#include "./parse-add-sub-expression.hpp"


std::optional<std::pair<Expression, int>> parse_expression(Tokens tokens) {
  return parse_add_sub_expression(tokens);
}