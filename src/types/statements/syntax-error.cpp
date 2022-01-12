#include "syntax-error.hpp"


SyntaxError::SyntaxError() = default;

void SyntaxError::setMessage(std::string message) {
  message_ = message;
}

void SyntaxError::setFrontToken(Token front_token) {
  front_token_ = front_token;
}

std::string SyntaxError::message() const {
  return message_;
}

Token SyntaxError::front_token() const {
  return front_token_;
}