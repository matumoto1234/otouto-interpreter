#pragma once

#include "../../../types/statements/source.hpp"
#include "../expression-parsers/parse-expression.hpp"


namespace {
  bool has_semicolon(Token token) {
    if (std::holds_alternative<SymbolToken>(token)) {
      SymbolToken symbol_token = std::get<SymbolToken>(token);

      if (std::holds_alternative<Semicolon>(symbol_token.type())) return true;
    }

    return false;
  }
}


std::optional<std::pair<Statement, int>> parse_statement(Tokens tokens) {
  const auto parsed_expr = parse_expression(tokens);

  if (not parsed_expr.has_value()) return std::nullopt;

  const auto [expr, parsed_tokens_count] = parsed_expr.value();

  int reading_pos = parsed_tokens_count;
  if (has_semicolon(tokens[reading_pos])) {
    std::pair<Statement, int> res;

    res.first = expr;
    res.second = parsed_tokens_count + /* SymbolToken(Semicolon) */ 1;

    return std::optional(res);
  }

  return std::nullopt;
}
