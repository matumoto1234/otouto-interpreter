#pragma once

#include "../expressions/expression.hpp"
#include "./assignment.hpp"


// IfStatment
class IfStatement;


using Statement = std::variant<IfStatement, Assignment, Expression>;

using Statements = std::vector<Statement>;
using StatementPointers = std::vector<std::shared_ptr<Statement>>;
using OptionalStatements = std::vector<std::optional<Statement>>;


class ElseStatement {
  StatementPointers statements_;

public:
  ElseStatement();

  void setStatements(std::vector<Statement>);
  OptionalStatements statements() const;
};


class IfStatement {
  Expression condition_;
  std::vector<std::shared_ptr<Statement>> if_statements_, else_statements_;

public:
  IfStatement();

  void setCondition(Expression);
  void setIfStatements(Statements);
  void setElseStatements(Statements);
  Expression condition() const;
  OptionalStatements ifStatements() const;
  OptionalStatements elseStatements() const;
};
