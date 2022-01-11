#include "./assignment.hpp"


// Assignment
Assignment::Assignment() = default;


void Assignment::setVariableName(std::string variable_name) {
  variable_name_ = variable_name;
}

void Assignment::setExpression(Expression expression) {
  expression_ = expression;
}

std::string Assignment::variableName() const {
  return variable_name_;
}

Expression Assignment::expression() const {
  return expression_;
}