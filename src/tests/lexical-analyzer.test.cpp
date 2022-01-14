#include "../modules/lexical-analyzer.hpp"

#include <iutest.hpp>
#include <type_traits>

int main(int argc, char **argv) {
  IUTEST_INIT(&argc, argv);
  return IUTEST_RUN_ALL_TESTS();
}

IUTEST(LexicalAnalyzerTest, isDigit1) {
  bool result = is_digit('0');
  IUTEST_ASSERT_EQ(result, true);
}

IUTEST(LexicalAnalyzerTest, isDigit2) {
  bool result = is_digit('-');
  IUTEST_ASSERT_EQ(result, false);
}


IUTEST(LexicalAnalyzerTest, countDigits1) {
  int result = count_digits("testtest");
  IUTEST_ASSERT_EQ(result, 0);
}

IUTEST(LexicalAnalyzerTest, countDigits2) {
  int result = count_digits("00000test");
  IUTEST_ASSERT_EQ(result, 5);
}


IUTEST(LexicalAnalyzerTest, isIdentifier1) {
  bool result = is_identifier('a');
  IUTEST_ASSERT_EQ(result, true);
}

IUTEST(LexicalAnalyzerTest, isIdentifier2) {
  bool result = is_identifier('-');
  IUTEST_ASSERT_EQ(result, false);
}


IUTEST(LexicalAnalyzerTest, countIdentifiers1) {
  int result = count_identifiers("aaaa+--");
  IUTEST_ASSERT_EQ(result, 4);
}

IUTEST(LexicalAnalyzerTest, countIdentifiers2) {
  int result = count_identifiers("+_+");
  IUTEST_ASSERT_EQ(result, 0);
}

IUTEST(LexicalAnalyzerTest, countIdentifiers3) {
  int result = count_identifiers("a/a/a");
  IUTEST_ASSERT_EQ(result, 1);
}


IUTEST(LexicalAnalyzerTest, lexicalAnalyzer1) {
  Tokens result = lexical_analyze("+-*/");

  bool has_plus = std::holds_alternative<Plus>(std::get<SymbolToken>(result[0]).type());
  IUTEST_ASSERT_EQ(has_plus, true);

  bool has_minus = std::holds_alternative<Minus>(std::get<SymbolToken>(result[1]).type());
  IUTEST_ASSERT_EQ(has_minus, true);

  bool has_asterisk = std::holds_alternative<Asterisk>(std::get<SymbolToken>(result[2]).type());
  IUTEST_ASSERT_EQ(has_asterisk, true);

  bool has_slash = std::holds_alternative<Slash>(std::get<SymbolToken>(result[3]).type());
  IUTEST_ASSERT_EQ(has_slash, true);
}