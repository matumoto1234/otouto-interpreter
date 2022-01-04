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