#pragma once

#include "./statement.hpp"
#include "./define-function.hpp"


using Source = std::vector<std::variant<Statement, DefineFunction>>;