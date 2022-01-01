#include <iutest.hpp>
#include "../modules/lexical-analyzer.hpp"

int main(int argc, char **argv) {
  IUTEST_INIT(&argc, argv);
  return IUTEST_RUN_ALL_TESTS();
}

IUTEST(LexicalAnalyzerTest, isDigit1) {
  bool result = lexical_analyzer::is_digit('0');
  IUTEST_ASSERT_EQ(result, true);
}