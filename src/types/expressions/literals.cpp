#include "./literals.hpp"


// IntLiteral
IntLiteral::IntLiteral(): value_(0) {
}

IntLiteral::IntLiteral(int v): value_(v) {
}

int IntLiteral::value() const {
  return value_;
}

void IntLiteral::setValue(int v) {
  value_ = v;
}

bool IntLiteral::operator==(const IntLiteral &other) const {
  return value_ == other.value_;
}


// BoolLiteral
BoolLiteral::BoolLiteral(): value_(false) {
}

BoolLiteral::BoolLiteral(bool v): value_(v) {
}

bool BoolLiteral::value() const {
  return value_;
}

void BoolLiteral::setValue(bool v) {
  value_ = v;
}

bool BoolLiteral::operator==(const BoolLiteral &other) const {
  return value_ == other.value_;
}


// NullLiteral
NullLiteral::NullLiteral() = default;

bool NullLiteral::operator==(const NullLiteral &other) const {
  return true;
}