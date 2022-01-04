#pragma once

#include "./literals.hpp"
#include "./variable.hpp"

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

  void setName(std::string n);
  void setArguments(std::vector<Expression> a);
  std::string name() const;
  std::vector<std::optional<Expression>> arguments() const;
};


// InfixOperators
namespace internal_infix_operator {
  class InfixOperator {
    std::shared_ptr<Expression> lhs_, rhs_;

  public:
    InfixOperator();

    void setLhs(Expression);
    void setRhs(Expression);
    std::optional<Expression> lhs() const;
    std::optional<Expression> rhs() const;
  };
} // namespace internal_infix_operator

class Add: internal_infix_operator::InfixOperator {};
class Sub: internal_infix_operator::InfixOperator {};
class Mul: internal_infix_operator::InfixOperator {};
class Div: internal_infix_operator::InfixOperator {};

class OrOperator: internal_infix_operator::InfixOperator {};

class AndOperator: internal_infix_operator::InfixOperator {};



// UnaryOperators
namespace internal_unary_operator {
  class UnaryOperator {
    std::shared_ptr<Expression> rhs_;

  public:
    UnaryOperator();

    void setRhs(Expression);
    std::optional<Expression> rhs() const;
  };
} // namespace internal_unary_operator


class UnaryPlus: internal_unary_operator::UnaryOperator {};
class UnaryMinus: internal_unary_operator::UnaryOperator {};
class UnaryNot: internal_unary_operator::UnaryOperator {};