#pragma once

#include "../../../types/expressions/expression.hpp"
#include "../../../types/tokens.hpp"


// parse_literal: Tokens |-> (Literal, parsed tokens count)
// Constraints of Tokens := {IntToken or KeywordToken/BoolToken or KeywordToken/KeywordTokenWithoutBoolToken/Null}
std::optional<std::pair<Literal, int>> parse_literal(Tokens tokens) {
  if (tokens.empty()) return std::nullopt;

  if (std::holds_alternative<IntToken>(tokens.front())) {
    IntToken int_token = std::get<IntToken>(tokens.front());

    std::optional<std::pair<Literal, int>> res;
    res->first = IntLiteral(int_token.value());
    res->second = /* parsed tokens count(IntToken) */ 1;

    return res;
  }

  // KeywordToken = BoolToken or KeywordTokenWithoutBoolToken
  KeywordToken keyword_token = std::get<KeywordToken>(tokens.front());


  if (std::holds_alternative<BoolToken>(keyword_token)) {
    BoolToken bool_token = std::get<BoolToken>(keyword_token);

    std::optional<std::pair<Literal, int>> res;
    res->first = BoolLiteral(bool_token.value());
    res->second = /* parsed tokens count(BoolToken) */ 1;

    return res;
  }

  // KeywordTokenWithoutBoolToken
  if (std::holds_alternative<KeywordTokenWithoutBoolToken>(keyword_token)) {
    KeywordTokenWithoutBoolToken keyword_token_without_bool_token = std::get<KeywordTokenWithoutBoolToken>(keyword_token);

    // Constraints of type() := Null
    if (std::holds_alternative<Null>(keyword_token_without_bool_token.type())) {
      std::optional<std::pair<Literal, int>> res;
      res->first = NullLiteral{};
      res->second = /* parsed tokens count(KeywordTokenWithoutBoolToken) */ 1;

      return res;
    }
  }

  return std::nullopt;
}