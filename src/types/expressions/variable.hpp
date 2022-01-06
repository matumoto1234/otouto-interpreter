#pragma once

#include <string>

// Variable
class Variable {
  std::string variable_name_;

public:
  Variable();

  void setVariableName(std::string n);
  std::string variableName() const;

  bool operator==(const Variable &) const;
};
