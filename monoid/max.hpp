#pragma once

#include "func.hpp"
#include "monoid/base.hpp"

template <typename T>
struct MaxMonoid : BaseMonoid<T> {
  static constexpr T op(const T &x, const T &y) { return max(x, y); }
  static constexpr T id() { return -inf<T>; }
};