#pragma once

#include "./literals.hpp"
#include "./variable.hpp"

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

using ArithmeticOperator = std::variant<Add, Sub, Mul, Div>;

class OrOperator;
class AndOperator;

using LogicalOperator = std::variant<OrOperator, AndOperator>;


// UnaryOperator (declaration)
class UnaryPlus;
class UnaryMinus;
class UnaryNot;

using UnaryOperator = std::variant<UnaryPlus, UnaryMinus, UnaryNot>;


// Expression
using Expression = std::variant<Literal, Variable, FunctionCalling, ArithmeticOperator, LogicalOperator, UnaryOperator>;



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

  bool operator==(const FunctionCalling &) const;
};


// InfixOperators
namespace infix_operator_base {
  class InfixOperator {
    std::shared_ptr<Expression> lhs_, rhs_;

  public:
    InfixOperator();

    void setLhs(Expression);
    void setRhs(Expression);
    std::optional<Expression> lhs() const;
    std::optional<Expression> rhs() const;

    bool operator==(const InfixOperator &) const;
  };
} // namespace infix_operator_base

class Add: public infix_operator_base::InfixOperator {};
class Sub: public infix_operator_base::InfixOperator {};
class Mul: public infix_operator_base::InfixOperator {};
class Div: public infix_operator_base::InfixOperator {};

class OrOperator: public infix_operator_base::InfixOperator {};
class AndOperator: public infix_operator_base::InfixOperator {};



// UnaryOperators
namespace unary_operator_base {
  class UnaryOperator {
    std::shared_ptr<Expression> rhs_;

  public:
    UnaryOperator();

    void setRhs(Expression);
    std::optional<Expression> rhs() const;

    bool operator==(const unary_operator_base::UnaryOperator &) const;
  };
} // namespace unary_operator_base


class UnaryPlus: public unary_operator_base::UnaryOperator {};
class UnaryMinus: public unary_operator_base::UnaryOperator {};
class UnaryNot: public unary_operator_base::UnaryOperator {};