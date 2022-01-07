#include "./tokens.hpp"

// SymbolToken
SymbolToken::SymbolToken() = default;
SymbolToken::SymbolToken(Symbol symbol): type_(symbol) {
}

Symbol SymbolToken::type() const {
  return type_;
}


// IdentifierToken
IdentifierToken::IdentifierToken() = default;

Identifier IdentifierToken::type() const {
  return type_;
}

void IdentifierToken::setIdentifierName(std::string identifier_name) {
  identifier_name_ = identifier_name;
}

std::string IdentifierToken::identifierName() const {
  return identifier_name_;
}


// IntToken
IntToken::IntToken(): value_(0) {
}
IntToken::IntToken(int value): value_(value) {
}

Int IntToken::type() const {
  return type_;
}

void IntToken::setValue(int value) {
  value_ = value;
}

int IntToken::value() const {
  return value_;
}


// BoolToken
BoolToken::BoolToken(): value_(false) {
}
BoolToken::BoolToken(bool value): value_(value) {
}

Bool BoolToken::type() const {
  return type_;
}

void BoolToken::setValue(bool value) {
  value_ = value;
}

bool BoolToken::value() const {
  return value_;
}


// KeywordTokenWithoutBoolToken
KeywordTokenWithoutBoolToken::KeywordTokenWithoutBoolToken() = default;
KeywordTokenWithoutBoolToken::KeywordTokenWithoutBoolToken(KeywordWithoutBool keyword): type_(keyword) {
}

KeywordWithoutBool KeywordTokenWithoutBoolToken::type() const {
  return type_;
}


// UnknownCharacterToken
UnknownCharacterToken::UnknownCharacterToken(): value_("") {
}
UnknownCharacterToken::UnknownCharacterToken(std::string value): value_(value) {
}

UnknownCharacter UnknownCharacterToken::type() const {
  return type_;
}

void UnknownCharacterToken::setValue(std::string value) {
  value_ = value;
}

std::string UnknownCharacterToken::value() const {
  return value_;
}