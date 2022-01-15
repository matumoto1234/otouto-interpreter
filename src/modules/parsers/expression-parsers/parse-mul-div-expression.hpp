#pragma once

#include "./parse-parentheses.hpp"


bool has_asterisk(Token token) {
  if (std::holds_alternative<SymbolToken>(token)) {
    SymbolToken symbol_token = std::get<SymbolToken>(token);

    if (std::holds_alternative<Asterisk>(symbol_token.type())) return true;
  }

  return false;
}

bool has_slash(Token token) {
  if (std::holds_alternative<SymbolToken>(token)) {
    SymbolToken symbol_token = std::get<SymbolToken>(token);

    if (std::holds_alternative<Slash>(symbol_token.type())) return true;
  }

  return false;
}


// parse_mul_div_expression: Tokens |-> (Expression, parsed tokens count)
// Constraints of Tokens := {Expression {(Asterisk or Slash) Expression}*}
std::optional<std::pair<Expression, int>> parse_mul_div_expression(Tokens tokens) {
  const std::optional<std::pair<Expression, int>> parsed_expr = parse_parentheses(tokens);

  if (not parsed_expr.has_value()) return std::nullopt;

  const auto [front_expr, front_tokens_count] = parsed_expr.value();

  int reading_pos = front_tokens_count;

  Expression lhs_expr = front_expr;

  while (has_asterisk(tokens[reading_pos]) or has_slash(tokens[reading_pos])) {
    const auto next_parsed_expr = parse_parentheses(Tokens(tokens.begin() + reading_pos, tokens.end()));

    if (not next_parsed_expr.has_value()) return std::nullopt;

    const auto [rhs_expr, rhs_tokens_count] = next_parsed_expr.value();

    if (has_asterisk(tokens[reading_pos])) {
      Mul mul;
      mul.setLhs(lhs_expr);
      mul.setRhs(rhs_expr);

      lhs_expr = mul;
    } else {
      Div div;
      div.setLhs(lhs_expr);
      div.setRhs(rhs_expr);

      lhs_expr = div;
    }

    reading_pos += rhs_tokens_count + /* SymbolToken */ 1;
  }

  std::pair<Expression, int> res;

  res.first = lhs_expr;
  res.second = reading_pos;

  return std::optional(res);
}