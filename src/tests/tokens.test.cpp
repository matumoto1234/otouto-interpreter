#include "../types/tokens.hpp"

#include <iutest.hpp>
#include <type_traits>

int main(int argc, char **argv) {
  IUTEST_INIT(&argc, argv);
  return IUTEST_RUN_ALL_TESTS();
}


IUTEST(TokensTest, SymbolTokenTest1) {
  SymbolToken s;

  bool result = std::is_same_v<decltype(s.type()), Symbol>;

  IUTEST_ASSERT_EQ(result, true);
}


IUTEST(TokensTest, IdentifierTokenTest) {
  IdentifierToken i;

  bool result = std::is_same_v<decltype(i.type()), Identifier>;

  IUTEST_ASSERT_EQ(result, true);

  i.setIdentifierName("test");
  IUTEST_ASSERT_EQ(i.identifierName(), "test");
}


IUTEST(TokensTest, IntTokenTest1) {
  IntToken i;

  bool result = std::is_same_v<decltype(i.type()), Int>;

  IUTEST_ASSERT_EQ(result, true);

  i.setValue(314);
  IUTEST_ASSERT_EQ(i.value(), 314);
}

IUTEST(TokensTest, IntTokenTest2) {
  IntToken i(314);

  IUTEST_ASSERT_EQ(i.value(), 314);

  i.setValue(216);

  IUTEST_ASSERT_EQ(i.value(), 216);
}


IUTEST(TokensTest, BoolTokenTest1) {
  BoolToken b;

  bool result = std::is_same_v<decltype(b.type()), Bool>;

  IUTEST_ASSERT_EQ(result, true);

  IUTEST_ASSERT_EQ(b.value(), false);

  b.setValue(true);
  IUTEST_ASSERT_EQ(b.value(), true);
}

IUTEST(TokensTest, BoolTokenTest2) {
  BoolToken b(true);

  IUTEST_ASSERT_EQ(b.value(), true);

  b.setValue(false);

  IUTEST_ASSERT_EQ(b.value(), false);
}


IUTEST(TokensTest, KeywordTokenWithoutBoolTokenTest1) {
  KeywordTokenWithoutBoolToken k;

  bool result = std::is_same_v<decltype(k.type()), KeywordWithoutBool>;

  IUTEST_ASSERT_EQ(result, true);
}

IUTEST(TokensTest, KeywordTokenWithoutBoolTokenTest2) {
  KeywordTokenWithoutBoolToken k(If{});
  
  bool result = std::holds_alternative<If>(k.type());

  IUTEST_ASSERT_EQ(result, true);

  k = KeywordTokenWithoutBoolToken(Def{});

  bool result2 = std::holds_alternative<Def>(k.type());

  IUTEST_ASSERT_EQ(result2, true);
}


IUTEST(TokensTest, UnknownCharacterTokenTest1) {
  UnknownCharacterToken u;

  bool result = std::is_same_v<decltype(u.type()), UnknownCharacter>;

  IUTEST_ASSERT_EQ(result, true);

  IUTEST_ASSERT_EQ(u.value(), "");

  u.setValue("test");

  IUTEST_ASSERT_EQ(u.value(), "test");
}

IUTEST(TokensTest, UnknownCharacterTokenTest2) {
  UnknownCharacterToken u("test");

  IUTEST_ASSERT_EQ(u.value(), "test");
}