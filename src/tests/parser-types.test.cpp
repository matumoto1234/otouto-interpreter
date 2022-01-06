#include "../types/expressions.hpp"

#include <iutest.hpp>

int main(int argc, char **argv) {
  IUTEST_INIT(&argc, argv);
  return IUTEST_RUN_ALL_TESTS();
}

IUTEST(ParserTypesTest, IntLiteralTest) {
  {
    IntLiteral i;
    IUTEST_ASSERT_EQ(i.value(), 0);
  }

  {
    IntLiteral i(10);
    IUTEST_ASSERT_EQ(i.value(), 10);
  }

  {
    IntLiteral i;
    i.setValue(20);
    IUTEST_ASSERT_EQ(i.value(), 20);
  }

  {
    IntLiteral i(30);
    i.setValue(20);
    IUTEST_ASSERT_EQ(i.value(), 20);
  }
}

IUTEST(ParserTypesTest, BoolLiteralTest) {
  {
    BoolLiteral b;
    IUTEST_ASSERT_EQ(b.value(), false);
  }

  {
    BoolLiteral b(true);
    IUTEST_ASSERT_EQ(b.value(), true);
  }

  {
    BoolLiteral b;
    b.setValue(true);
    IUTEST_ASSERT_EQ(b.value(), true);
  }

  {
    BoolLiteral b(false);
    b.setValue(true);
    IUTEST_ASSERT_EQ(b.value(), true);
  }
}

IUTEST(ParserTypesTest, VariableTest) {
  {
    Variable v;
    IUTEST_ASSERT_EQ(v.variableName(), "");
  }

  {
    Variable v;
    v.setVariableName("aaa");
    IUTEST_ASSERT_EQ(v.variableName(), "aaa");
  }
}

IUTEST(ParserTypesTest, FunctionCallingTest1) {
  FunctionCalling f;
  IUTEST_ASSERT_EQ(f.functionName(), "");
  IUTEST_ASSERT_EQ(f.arguments().empty(), true);
}

IUTEST(ParserTypesTest, FunctionCallingTest2) {
  FunctionCalling f;

  std::vector<Expression> a;
  a.push_back(IntLiteral(100));
  a.push_back(BoolLiteral(true));

  f.setArguments(a);

  IUTEST_ASSERT_EQ(f.arguments()[0].has_value(), true);
  Literal a0 = std::get<Literal>(f.arguments()[0].value());
  IUTEST_ASSERT_EQ(std::holds_alternative<IntLiteral>(a0), true);
  IUTEST_ASSERT_EQ(std::get<IntLiteral>(a0).value(), 100);

  IUTEST_ASSERT_EQ(f.arguments()[1].has_value(), true);
  Literal a1 = std::get<Literal>(f.arguments()[1].value());
  IUTEST_ASSERT_EQ(std::holds_alternative<BoolLiteral>(a1), true);
  IUTEST_ASSERT_EQ(std::get<BoolLiteral>(a1).value(), true);
}

IUTEST(ParserTypesTest, FunctionCallingTest3) {
  FunctionCalling f;

  f.setFunctionName("hogehoge");

  IUTEST_ASSERT_EQ(f.functionName(), "hogehoge");
}

IUTEST(ParserTypesTest, InfixOperatorTest1) {
  infix_operator_base::InfixOperator i;
  IUTEST_ASSERT_EQ(i.lhs(), std::nullopt);
  IUTEST_ASSERT_EQ(i.rhs(), std::nullopt);
}

IUTEST(ParserTypesTest, InfixOperatorTest2) {
  infix_operator_base::InfixOperator i;

  FunctionCalling f;

  std::vector<Expression> l;
  l.push_back(IntLiteral(100));

  f.setArguments(l);

  i.setLhs(f);

  IUTEST_ASSERT_EQ(std::get<FunctionCalling>(i.lhs().value()).arguments(), f.arguments());

  i.setRhs(IntLiteral(20));

  IUTEST_ASSERT_EQ(std::get<IntLiteral>(std::get<Literal>(i.rhs().value())).value(), 20);
}