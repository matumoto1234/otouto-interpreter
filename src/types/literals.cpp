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


// NullLiteral
NullLiteral::NullLiteral() = default;