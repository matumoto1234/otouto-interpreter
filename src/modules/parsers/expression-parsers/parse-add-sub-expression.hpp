#pragma once

#include "./parse-mul-div-expression.hpp"


namespace {
  bool has_plus(Token token) {
    if (std::holds_alternative<SymbolToken>(token)) {
      SymbolToken symbol_token = std::get<SymbolToken>(token);

      if (std::holds_alternative<Plus>(symbol_token.type())) return true;
    }

    return false;
  }

  bool has_minus(Token token) {
    if (std::holds_alternative<SymbolToken>(token)) {
      SymbolToken symbol_token = std::get<SymbolToken>(token);

      if (std::holds_alternative<Minus>(symbol_token.type())) return true;
    }

    return false;
  }
} // namespace


// parse_add_sub_expression: Tokens |-> (Expression, parsed tokens count)
// Constraints of Tokens := {Expression {(Plus or Minus) Expression}*}
std::optional<std::pair<Expression, int>> parse_add_sub_expression(Tokens tokens) {
  const std::optional<std::pair<Expression, int>> parsed_expr = parse_mul_div_expression(tokens);

  if (not parsed_expr.has_value()) return std::nullopt;

  const auto [front_expr, front_tokens_count] = parsed_expr.value();

  int reading_pos = front_tokens_count;

  Expression lhs_expr = front_expr;

  while (has_plus(tokens[reading_pos]) or has_minus(tokens[reading_pos])) {
    const auto next_parsed_expr = parse_mul_div_expression(Tokens(tokens.begin() + reading_pos, tokens.end()));

    if (not next_parsed_expr.has_value()) return std::nullopt;

    const auto [rhs_expr, rhs_tokens_count] = next_parsed_expr.value();

    if (has_plus(tokens[reading_pos])) {
      Add add;
      add.setLhs(lhs_expr);
      add.setRhs(rhs_expr);

      lhs_expr = add;
    } else {
      Sub sub;
      sub.setLhs(lhs_expr);
      sub.setRhs(rhs_expr);

      lhs_expr = sub;
    }

    reading_pos += rhs_tokens_count + /* SymbolToken */ 1;
  }

  std::pair<Expression, int> res;

  res.first = lhs_expr;
  res.second = reading_pos;

  return std::optional(res);
}
