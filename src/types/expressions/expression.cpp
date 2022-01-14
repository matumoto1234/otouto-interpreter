#include "./expression.hpp"


// FunctionCalling
FunctionCalling::FunctionCalling() = default;

void FunctionCalling::setFunctionName(std::string funciton_name) {
  function_name_ = funciton_name;
}

void FunctionCalling::setArguments(std::vector<Expression> arguments) {
  arguments_.assign(arguments.size(), nullptr);
  for (size_t i = 0; i < arguments.size(); i++) {
    arguments_[i] = std::make_shared<Expression>(arguments[i]);
  }
}

std::string FunctionCalling::functionName() const {
  return function_name_;
}

std::vector<std::optional<Expression>> FunctionCalling::arguments() const {
  std::vector<std::optional<Expression>> optional_arguments;
  optional_arguments.reserve(arguments_.size());
  for (std::shared_ptr<Expression> argument: arguments_) {
    if (argument == nullptr) {
      optional_arguments.push_back(std::nullopt);
    } else {
      optional_arguments.push_back(*argument);
    }
  }
  return optional_arguments;
}

bool FunctionCalling::operator==(const FunctionCalling &other) const {
  return (function_name_ == other.function_name_) and (arguments_ == other.arguments_);
}


// InfixOperator
namespace {
  using namespace infix_operator_base;
} // unnamed namespace

InfixOperator::InfixOperator(): lhs_(nullptr), rhs_(nullptr) {
}

void InfixOperator::setLhs(Expression e) {
  lhs_ = make_shared<Expression>(e);
}

void InfixOperator::setRhs(Expression e) {
  rhs_ = make_shared<Expression>(e);
}

std::optional<Expression> InfixOperator::lhs() const {
  if (lhs_ == nullptr) return std::nullopt;
  return *lhs_;
}

std::optional<Expression> InfixOperator::rhs() const {
  if (rhs_ == nullptr) return std::nullopt;
  return *rhs_;
}

bool InfixOperator::operator==(const InfixOperator &other) const {
  return (lhs_ == other.lhs_) and (rhs_ == other.rhs_);
}


// UnaryOperator
unary_operator_base::UnaryOperator::UnaryOperator(): rhs_(nullptr) {
}

void unary_operator_base::UnaryOperator::setRhs(Expression e) {
  rhs_ = make_shared<Expression>(e);
}

std::optional<Expression> unary_operator_base::UnaryOperator::rhs() const {
  if (rhs_ == nullptr) return std::nullopt;
  return *rhs_;
}

bool unary_operator_base::UnaryOperator::operator==(const unary_operator_base::UnaryOperator &other) const {
  return rhs_ == other.rhs_;
}