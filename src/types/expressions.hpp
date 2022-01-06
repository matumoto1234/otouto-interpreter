#pragma once

#include "./expressions/literals.hpp"
#include "./expressions/variable.hpp"

#include <concepts>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <vector>


// FunctionCalling (declaration)
class FunctionCalling;


// InfixOperators (declaration)
class Add;
class Sub;
class Mul;
class Div;

using ArithmeticOperators = std::variant<Add, Sub, Mul, Div>;

class OrOperator;
class AndOperator;

using LogicalOperators = std::variant<OrOperator, AndOperator>;


// UnaryOperator (declaration)
class UnaryPlus;
class UnaryMinus;
class UnaryNot;

using UnaryOperators = std::variant<UnaryPlus, UnaryMinus, UnaryNot>;


// Expression
using Expression = std::variant<Literal, Variable, FunctionCalling, ArithmeticOperators, LogicalOperators, UnaryOperators>;



// FunctionCalling
class FunctionCalling {
  std::string function_name_;
  std::vector<std::shared_ptr<Expression>> arguments_;

public:
  FunctionCalling();

  void setFunctionName(std::string);
  void setArguments(std::vector<Expression>);
  std::string functionName() const;
  std::vector<std::optional<Expression>> arguments() const;
};


// InfixOperators
namespace {
  class InfixOperator {
    std::shared_ptr<Expression> lhs_, rhs_;

  public:
    InfixOperator();

    void setLhs(Expression);
    void setRhs(Expression);
    std::optional<Expression> lhs() const;
    std::optional<Expression> rhs() const;
  };
} // namespace

class Add: InfixOperator {};
class Sub: InfixOperator {};
class Mul: InfixOperator {};
class Div: InfixOperator {};

class OrOperator: InfixOperator {};
class AndOperator: InfixOperator {};



// UnaryOperators
namespace {
  class UnaryOperator {
    std::shared_ptr<Expression> rhs_;

  public:
    UnaryOperator();

    void setRhs(Expression);
    std::optional<Expression> rhs() const;
  };
} // namespace


class UnaryPlus: UnaryOperator {};
class UnaryMinus: UnaryOperator {};
class UnaryNot: UnaryOperator {};