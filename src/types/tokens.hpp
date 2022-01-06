#pragma once

#include <string>
#include <variant>;


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

class SymbolToken {
  Symbol type_;

public:
  SymbolToken();
  SymbolToken(Symbol);

  Symbol type() const;
};

// Identifier
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

// ValueToken
class Int {};

class IntToken {
  
};