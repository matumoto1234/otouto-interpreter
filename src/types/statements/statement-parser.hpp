#pragma once

#include "../tokens.hpp"

#include <utility>

// <any value, parsed tokens count>
template <typename T>
using StatementParser = std::optional<std::pair<T, int>>;