#pragma once

#include "func.hpp"
#include "monoid/base.hpp"

template <typename T>
struct MinMonoid : BaseMonoid<T> {
  static constexpr T op(const T &x, const T &y) { return min(x, y); }
  static constexpr T id() { return inf<T>; }
};