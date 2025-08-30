#pragma once

#include "monoid/base.hpp"

template <typename T>
struct AddMonoid : BaseMonoid<T> {
  static constexpr T op(const T &x, const T &y) { return x + y; }
  static constexpr T id() { return 0; }
};