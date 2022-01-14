#pragma once

#include "../types/tokens.hpp"
#include "./lexical-analyzers/count-digits.hpp"
#include "./lexical-analyzers/count-identifiers.hpp"
#include "./lexical-analyzers/is-digit.hpp"
#include "./lexical-analyzers/is-identifier.hpp"


Tokens lexical_analyze(std::string source) {
  Tokens tokens;

  int size = source.size();
  for (int i = 0; i < size; i++) {
    switch (source[i]) {
      case '+':
        tokens.push_back(SymbolToken(Plus{}));
        break;
      case '-':
        tokens.push_back(SymbolToken(Minus{}));
        break;
      case '*':
        tokens.push_back(SymbolToken(Asterisk{}));
        break;
      case '/':
        tokens.push_back(SymbolToken(Slash{}));
        break;
      default:
        break;
    }
  }

  return tokens;
}
