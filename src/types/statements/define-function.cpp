#include "./define-function.hpp"


// DefineFunction
DefineFunction::DefineFunction() = default;

void DefineFunction::setFunctionName(std::string function_name) {
  function_name_ = function_name;
}

void DefineFunction::setArguments(std::vector<std::string> arguments) {
  arguments_ = arguments;
}

void DefineFunction::setStatements(std::vector<Statement> statements) {
  statements_ = statements;
}

std::string DefineFunction::functionName() const {
  return function_name_;
}

std::vector<std::string> DefineFunction::arguments() const {
  return arguments_;
}

std::vector<Statement> DefineFunction::statements() const {
  return statements_;
}
