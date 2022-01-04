#include "./expressions.hpp"


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


// InfixOperator
internal_infix_operator::InfixOperator::InfixOperator(): lhs_(nullptr), rhs_(nullptr) {
}

void internal_infix_operator::InfixOperator::setLhs(Expression e) {
  lhs_ = make_shared<Expression>(e);
}

void internal_infix_operator::InfixOperator::setRhs(Expression e) {
  rhs_ = make_shared<Expression>(e);
}

std::optional<Expression> internal_infix_operator::InfixOperator::lhs() const {
  return *lhs_;
}

std::optional<Expression> internal_infix_operator::InfixOperator::rhs() const {
  return *rhs_;
}


// UnaryOperator
internal_unary_operator::UnaryOperator::UnaryOperator(): rhs_(nullptr) {
}

void internal_unary_operator::UnaryOperator::setRhs(Expression e) {
  rhs_ = make_shared<Expression>(e);
}

std::optional<Expression> internal_unary_operator::UnaryOperator::rhs() const {
  return *rhs_;
}
