#pragma once

#include "./parse-expression.hpp"
#include "./parse-value.hpp"


// Prototype declaration
std::optional<std::pair<Expression, int>> parse_expression(Tokens);


// parse_parenthesis: Tokens |-> (Expression, parsed tokens count)
// Constraints of Tokens := {LParen Expression RParen}
std::optional<std::pair<Expression, int>> parse_parentheses(Tokens tokens) {
  if (not std::holds_alternative<LParen>(tokens.front())) return parse_value(tokens);

  std::optional<std::pair<Expression, int>> parsed_expr = parse_expression(Tokens(tokens.begin() + 1, tokens.end()));

  if (not parsed_expr.has_value()) return std::nullopt;

  const auto [expr, parsed_tokens_count] = parsed_expr.value();

  Token next_token = tokens[parsed_tokens_count + 1];
  if (std::holds_alternative<SymbolToken>(next_token)) {
    SymbolToken symbol_token = std::get<SymbolToken>(next_token);

    if (std::holds_alternative<Parens>(symbol_token.type())) {
      Parens parens = std::get<Parens>(symbol_token.type());

      if (std::holds_alternative<RParen>(parens)) {
        std::pair<Expression, int> res;

        res.first = expr;
        res.second = parsed_tokens_count + /* LParen + RParen */ 2;

        return std::optional(res);
      }
    }
  }

  return std::nullopt;
}