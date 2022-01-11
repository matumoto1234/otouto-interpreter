#pragma once

#include "./statement.hpp"


class DefineFunction {
  std::string function_name_;
  std::vector<std::string> arguments_;
  Statements statements_;

public:
  DefineFunction();

  void setFunctionName(std::string);
  void setArguments(std::vector<std::string>);
  void setStatements(std::vector<Statement> statements_);
  std::string functionName() const;
  std::vector<std::string> arguments() const;
  Statements statements() const;
};