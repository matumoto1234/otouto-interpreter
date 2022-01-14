#include "./statement.hpp"


// ElseStatement
ElseStatement::ElseStatement() = default;

void ElseStatement::setStatements(Statements statements) {
  statements_.assign(statements.size(), nullptr);
  for (size_t i = 0; i < statements.size(); i++) {
    statements_[i] = std::make_shared<Statement>(statements[i]);
  }
}

OptionalStatements ElseStatement::statements() const {
  OptionalStatements optional_statements;
  optional_statements.reserve(statements_.size());

  for (std::shared_ptr<Statement> statement: statements_) {
    if (statement == nullptr) {
      optional_statements.push_back(std::nullopt);
    } else {
      optional_statements.push_back(*statement);
    }
  }
  return optional_statements;
}


// IfStatement
IfStatement::IfStatement() = default;

void IfStatement::setCondition(Expression expression) {
  condition_ = expression;
}

void IfStatement::setIfStatements(Statements if_statements) {
  if_statements_.assign(if_statements.size(), nullptr);

  for (size_t i = 0; i < if_statements.size(); i++) {
    if_statements_[i] = std::make_shared<Statement>(if_statements[i]);
  }
}

void IfStatement::setElseStatements(Statements else_statements) {
  else_statements_.assign(else_statements.size(), nullptr);

  for (size_t i = 0; i < else_statements.size(); i++) {
    else_statements_[i] = std::make_shared<Statement>(else_statements[i]);
  }
}

Expression IfStatement::condition() const {
  return condition_;
}

OptionalStatements IfStatement::ifStatements() const {
  OptionalStatements optional_if_statements;
  optional_if_statements.reserve(if_statements_.size());

  for (std::shared_ptr<Statement> statement: if_statements_) {
    if (statement == nullptr) {
      optional_if_statements.push_back(std::nullopt);
    } else {
      optional_if_statements.push_back(*statement);
    }
  }
  return optional_if_statements;
}

OptionalStatements IfStatement::elseStatements() const {
  OptionalStatements optional_else_statements;
  optional_else_statements.reserve(else_statements_.size());

  for (std::shared_ptr<Statement> statement: else_statements_) {
    if (statement == nullptr) {
      optional_else_statements.push_back(std::nullopt);
    } else {
      optional_else_statements.push_back(*statement);
    }
  }
  return optional_else_statements;
}