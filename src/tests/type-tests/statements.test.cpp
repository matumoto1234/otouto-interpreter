#include "../../types/statements/statement.hpp"

#include <iutest.hpp>

int main(int argc, char **argv) {
  IUTEST_INIT(&argc, argv);
  return IUTEST_RUN_ALL_TESTS();
}



IUTEST(StatementsTest, StatementTest1) {
  Statement s;
  s = IntLiteral(10);

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(get<Expression>(s))).value(), 10);
}

IUTEST(StatementsTest, StatementTest2) {
  Statement s;
  s = BoolLiteral(true);

  IUTEST_ASSERT_EQ(get<BoolLiteral>(get<Literal>(get<Expression>(s))).value(), true);
}


IUTEST(StatementsTest, AssignmentTest1) {
  Assignment a;

  a.setExpression(IntLiteral(15));
  a.setVariableName("hogehoge");

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(a.expression())).value(), 15);
}

IUTEST(StatementsTest, AssignmentTest2) {
  Assignment a;

  a.setExpression(IntLiteral(15));
  a.setVariableName("hogehoge");

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(a.expression())).value(), 15);

  Statement s = a;

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(a.expression())).value(), 15);
}


IUTEST(StatementsTest, ElseStatementTest) {
  ElseStatement es;

  Statements ss;

  ss.push_back(IntLiteral(30));
  ss.push_back(BoolLiteral(true));

  es.setStatements(ss);

  OptionalStatements os = es.statements();

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(get<Expression>(os[0].value()))).value(), 30);
  IUTEST_ASSERT_EQ(get<BoolLiteral>(get<Literal>(get<Expression>(os[1].value()))).value(), true);
}


IUTEST(StatementsTest, IfStatementTest) {
  IfStatement is;

  is.setCondition(BoolLiteral(true));

  {
    Statements ss;

    ss.push_back(IntLiteral(30));
    ss.push_back(BoolLiteral(true));

    is.setIfStatements(ss);
  }

  OptionalStatements os = is.ifStatements();

  IUTEST_ASSERT_EQ(get<BoolLiteral>(get<Literal>(is.condition())).value(), true);

  IUTEST_ASSERT_EQ(os.size(), 2);

  IUTEST_ASSERT_EQ(get<IntLiteral>(get<Literal>(get<Expression>(os[0].value()))).value(), 30);
  IUTEST_ASSERT_EQ(get<BoolLiteral>(get<Literal>(get<Expression>(os[1].value()))).value(), true);
}