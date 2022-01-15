#pragma once

#include "./parse-literal.hpp"


// parse_value: Tokens |-> (Literal or Variable, parsed tokens count)
// Constraints of Tokens := {Identifier}
std::optional<std::pair<Expression, int>> parse_value(Tokens tokens) {
  if (std::holds_alternative<IdentifierToken>(tokens.front())) {
    IdentifierToken identifier_token = std::get<IdentifierToken>(tokens.front());

    Variable variable;
    variable.setVariableName(identifier_token.identifierName());

    std::optional<std::pair<Expression, int>> res;
    res->first = variable;
    res->second = /* parsed tokens count(IdentifierToken) */ 1;
  }

  return parse_literal(tokens);
}
