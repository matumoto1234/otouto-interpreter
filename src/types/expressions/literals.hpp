#pragma once

#include <variant>

// Literals
class IntLiteral {
  int value_;

public:
  IntLiteral();
  IntLiteral(int v);

  int value() const;
  void setValue(int v);
};

class BoolLiteral {
  bool value_;

public:
  BoolLiteral();
  BoolLiteral(bool v);

  bool value() const;
  void setValue(bool v);
};

class NullLiteral {
public:
  NullLiteral();
};

using Literal = std::variant<BoolLiteral, BoolLiteral, NullLiteral>;