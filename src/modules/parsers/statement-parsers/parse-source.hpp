#pragma once

#include "../../../types/statements/source.hpp"
#include "../../../types/statements/syntax-error.hpp"
#include "./parse-statement.hpp"

#include <cxxabi.h>

namespace {
  char *demangle(const char *demangle) {
    int status;
    return abi::__cxa_demangle(demangle, 0, 0, &status);
  }
} // namespace

std::variant<Source, SyntaxError> parse_source(Tokens tokens) {
  Source parts_of_source;

  int reading_pos = 0;
  const int size = tokens.size();
  while (reading_pos < size) {
    const auto parsed_stmt = parse_statement(Tokens(tokens.begin() + reading_pos, tokens.end()));

    if (parsed_stmt.has_value()) {
      const auto [stmt, parsed_tokens_count] = parsed_stmt.value();

      parts_of_source.push_back(stmt);
      reading_pos += parsed_tokens_count;
      continue;
    }

    SyntaxError syntax_error;

    const std::string token_name = demangle(typeid(tokens[reading_pos]).name());
    syntax_error.setMessage("予期しないトークン" + token_name + "が渡されました");
    syntax_error.setFrontToken(tokens[reading_pos]);
    return syntax_error;
  }


  return parts_of_source;
}
