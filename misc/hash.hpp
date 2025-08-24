#pragma once

#include "random.hpp"

struct Hash {
  u64 operator()(const integer auto x) const
    requires (sizeof(x) != 16) {
    u64 y = x + FIXED_RND64;
    y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
    y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
    return y ^ (y >> 31);
  }

  u64 operator()(const integer auto x) const
    requires (sizeof(x) == 16) {
    return operator()(u64(x), u64(x >> 64));
  }

  u64 operator()(const auto &...args) const {
    u64 s{};
    ((s = s * FIXED_RND32 + operator()(args)), ...);
    return s;
  }
  u64 operator()(const R::forward_range auto &v) const {
    u64 s{};
    fre (x, v) s = s * FIXED_RND32 + operator()(x);
    return s;
  }

  template <typename T1, typename T2>
  u64 operator()(const std::pair<T1, T2> &p) const { return operator()(p.first, p.second); }
  template <typename... Args>
  u64 operator()(const std::tuple<Args...> &t) const {
    return std::apply([&](auto &&...args) { return operator()(args...); }, t);
  }
} hash;