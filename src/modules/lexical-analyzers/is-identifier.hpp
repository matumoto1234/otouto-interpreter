#pragma once

bool is_identifier(char ch) {
  return ('a' <= ch and ch <= 'z') or ('A' <= ch and ch <= 'Z');
}