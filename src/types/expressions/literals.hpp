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

  bool operator==(const IntLiteral &) const;
};

class BoolLiteral {
  bool value_;

public:
  BoolLiteral();
  BoolLiteral(bool v);

  bool value() const;
  void setValue(bool v);

  bool operator==(const BoolLiteral &) const;
};

class NullLiteral {
public:
  NullLiteral();

  bool operator==(const NullLiteral &) const;
};

using Literal = std::variant<IntLiteral, BoolLiteral, NullLiteral>;