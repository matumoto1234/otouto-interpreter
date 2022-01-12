#pragma once

#include "../expressions.hpp"


class Assignment {
  std::string variable_name_;
  Expression expression_;

public:
  Assignment();

  void setVariableName(std::string);
  void setExpression(Expression);
  std::string variableName() const;
  Expression expression() const;
};