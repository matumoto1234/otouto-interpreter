#pragma once

#include "./expressions.hpp"
#include "./statements/assignment.hpp"


// IfStatment
class IfStatement;


using Statement = std::variant<IfStatement, Assignment, Expression>;

using Statements = std::vector<Statement>;
using StatementPointers = std::vector<std::shared_ptr<Statement>>;
using OptionalStatements = std::vector<std::optional<Statement>>;


class ElseStatement {
  std::vector<std::shared_ptr<Statement>> statements_;

public:
  ElseStatement();

  void setStatements(std::vector<Statement>);
  std::vector<std::optional<Statement>> statements() const;
};


class IfStatement {
  Expression condition_;
  std::vector<std::shared_ptr<Statement>> if_statements_, else_statements_;

public:
  IfStatement();

  void setCondition(Expression);
  void setIfStatements(std::vector<Expression>);
  void setElseSatements(std::vector<Expression>);
  Expression condition() const;
  std::vector<std::optional<Statement>> ifStatements() const;
  std::vector<std::optional<Statement>> elseStatements() const;
};
