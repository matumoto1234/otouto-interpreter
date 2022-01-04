#include "./variable.hpp"

// Variable
Variable::Variable() = default;

void Variable::setName(std::string n) {
  variable_name_ = n;
}

std::string Variable::variableName() const {
  return variable_name_;
}