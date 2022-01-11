#include "./assignment.hpp"


// Assignment
Assignment::Assignment() = default;

std::string Assignment::variableName() {
  return variable_name_;
}

Expression Assignment::expression() {
  return expression_;
}

void Assignment::setVariableName(std::string variable_name){
  variable_name_ = variable_name;
}

void Assignment::setExpression(Expression expression) {
  expression_ = expression;
}