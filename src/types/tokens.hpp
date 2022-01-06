#pragma once

#include <string>
#include <variant>
#include <vector>


// Symbols
class LParen {};
class RParen {};
using Parens = std::variant<LParen, RParen>;

class LBrace {};
class RBrace {};
using Braces = std::variant<LBrace, RBrace>;

class Not {};
class And {};
class Pipe {};
class AndAnd {};
class PipePipe {};
using LogicalSymbol = std::variant<Not, And, Pipe, AndAnd, PipePipe>;

class LessThan {};
class LessEqual {};
class EqualEqual {};
class NotEqual {};
using CompareSymbol = std::variant<LessThan, LessEqual, EqualEqual, NotEqual>;

class Plus {};
class Minus {};
class Asterisk {};
class Slash {};
class Comma {};
class Semicolon {};
using Symbol = std::variant<Plus, Minus, Asterisk, Slash, Comma, Semicolon, Parens, Braces, LogicalSymbol, CompareSymbol>;


// SymbolToken
class SymbolToken {
  Symbol type_;

public:
  SymbolToken();
  SymbolToken(Symbol);

  Symbol type() const;
};


// IdentifierToken
class Identifier {};

class IdentifierToken {
  Identifier type_;
  std::string identifier_name_;

public:
  IdentifierToken();

  Identifier type() const;
  void setIdentifierName(std::string);
  std::string identifierName() const;
};


// IntToken
class Int {};

class IntToken {
  Int type_;
  int value_;

public:
  IntToken();
  IntToken(int);

  Int type() const;
  void setValue(int);
  int value() const;
};


// BoolToken
class Bool {};

class BoolToken {
  Bool type_;
  bool value_;

public:
  BoolToken();
  BoolToken(bool);

  Bool type() const;
  void setValue(bool);
  bool value() const;
};


// Keyword
class If {};
class Else {};
class Def {};
class Null {};
using Keyword = std::variant<If, Else, Def, Null>;


// KeywordToken
class KeywordTokenWithoutBoolToken {
  Keyword type_;

public:
  KeywordTokenWithoutBoolToken();
  KeywordTokenWithoutBoolToken(Keyword);

  Keyword type() const;
};

using KeywordToken = std::variant<BoolToken, KeywordTokenWithoutBoolToken>;


// UnknownCharacterToken
class UnknownCharacter {};

class UnknownCharacterToken {
  UnknownCharacter type_;
  std::string value_;

public:
  UnknownCharacterToken();
  UnknownCharacterToken(std::string);

  UnknownCharacter type() const;
  void setValue(std::string);
  std::string value() const;
};


// Token
using Token = std::variant<SymbolToken, IdentifierToken, IntToken, KeywordToken, UnknownCharacterToken>;

using Tokens = std::vector<Token>;