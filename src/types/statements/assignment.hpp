#pragma once

#include "../expressions.hpp"


class Assignment {
  std::string variable_name_;
  Expression expression_;

public:
  Assignment();

  std::string variableName();
  Expression expression();
  void setVariableName(std::string);
  void setExpression(Expression);
};