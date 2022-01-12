#pragma once

#include "../tokens.hpp"


class SyntaxError {
  std::string message_;
  Token front_token_;

public:
  SyntaxError();

  void setMessage(std::string);
  void setFrontToken(Token);
  std::string message();
  Token front_token();
};