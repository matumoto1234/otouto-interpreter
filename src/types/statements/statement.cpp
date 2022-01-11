#include "./statement.hpp"


// ElseStatement
ElseStatement::ElseStatement() = default;

std::vector<std::optional<Statement>> ElseStatement::statements() const {
  std::vector<std::optional<Statement>> optional_statements;
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

Expression IfStatement::condition() const {
  return condition_;
}

std::vector<std::optional<Statement>> IfStatement::ifStatements() const {
  std::vector<std::optional<Statement>> optional_if_statements;
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

std::vector<std::optional<Statement>> IfStatement::elseStatements() const {
  std::vector<std::optional<Statement>> optional_else_statements;
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