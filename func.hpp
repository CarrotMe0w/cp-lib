#pragma once

#include <bits/stdc++.h>

using namespace std::literals;
namespace R = std::ranges;
namespace V = std::views;

#include "types.hpp"

#define CONCAT0(a, b) a##b
#define CONCAT(a, b) CONCAT0(a, b)

#define GET1(a, ...) a
#define GET2(a, b, ...) b
#define GET3(a, b, c, ...) c
#define GET4(a, b, c, d, ...) d
#define GET5(a, b, c, d, e, ...) e
#define GET6(a, b, c, d, e, f, ...) f
#define GET9(a, b, c, d, e, f, g, h, i, ...) i
#define GET_LAST(...) CONCAT(GET, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)
#define DROP_LAST1(a)
#define DROP_LAST2(a, b) a
#define DROP_LAST3(a, b, c) a, b
#define DROP_LAST4(a, b, c, d) a, b, c
#define DROP_LAST5(a, b, c, d, e) a, b, c, d
#define DROP_LAST(...) CONCAT(DROP_LAST, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)

#define ARGSNUM(...) GET6(__VA_ARGS__ __VA_OPT__(, ) 5, 4, 3, 2, 1, 0)

#define FR0() while (true)
#define FR1(a) FR2(_, a)
#define FR2(i, a) for (std::decay_t<decltype(a)> i = 0; i < (a); i++)
#define FR3(i, a, b) for (std::common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define FR4(i, a, b, c) for (std::common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define fr(...) CONCAT(FR, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)
#define FRI2(i, a) for (auto i = (a); i--;)
#define FRI3(i, b, a) for (auto i = (b); i-- > (a);)
#define fri(...) CONCAT(FRI, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)

#define FRE1(a) a
#define FRE2(...) [__VA_ARGS__]
#define FRE_ARGS(...) GET5(__VA_ARGS__, FRE2, FRE2, FRE2, FRE1)(__VA_ARGS__)
#define fre(...) for (auto &&FRE_ARGS(DROP_LAST(__VA_ARGS__)) : GET_LAST(__VA_ARGS__))

#define all(a) R::begin(a), R::end(a)

#define FWD(x) std::forward<decltype(x)>(x)

#define j0 __j0
#define j1 __j1
#define y0 __y0
#define y1 __y1

#define exec _exec | [&]
struct exec_t {
  void operator|(auto &&func) { func(); }
} _exec;

constexpr auto floordiv(auto &&x, auto &&y) { return x / y - (x % y && x < 0 ^ y < 0); }
constexpr auto ceildiv(auto &&x, auto &&y) { return floordiv(x + y - 1, y); }
constexpr auto divmod(auto &&x, auto &&y) {
  auto &&d = floordiv(x, y);
  return std::pair{d, x - y * d};
}

template <auto base = 10>
constexpr int lg(auto &&n) {
  if constexpr (base == 2) return n <= 2 ? 1 : std::bit_width<to_unsigned_t<decltype(n - 1)>>(n - 1);
  return n <= base ? 1 : lg<base>(n / base) + 1;
}
template <typename T = u64>
constexpr T pw(const auto base, auto &&n) { return n == 0 ? 1 : pw<T>(base, n - 1) * base; }
template <typename T>
constexpr T truncate(const T &&n) {
  T p = pw<T>(10, lg(n) - 1);
  return n / p * p;
}

template <typename T>
constexpr T inf = truncate(std::numeric_limits<T>::max() >> 1);
template <>
constexpr f64 inf<f64> = inf<u64>;
template <>
constexpr fld inf<fld> = inf<u64>;

template <typename T = int>
auto dvec(size_t n) { return vec<T>(n); }
template <typename T = int>
auto dvec(size_t n, auto &&...args) { return vec(n, dvec<T>(args...)); }
template <typename T = int>
auto fvec(size_t n, T x) { return vec<T>(n, x); }
template <typename T = int>
auto fvec(size_t n, auto &&...args)
  requires (sizeof...(args) >= 2) { return vec(n, fvec<T>(args...)); }

constexpr int len(auto &&c) { return R::size(c); }

constexpr int lb(R::forward_range auto &&c, const auto &val, auto... args) {
  return R::lower_bound(c, val, args...) - R::begin(c);
}
constexpr int ub(R::forward_range auto &&c, const auto &val, auto... args) {
  return R::upper_bound(c, val, args...) - R::begin(c);
}

constexpr auto max(const auto &x) { return x; }
constexpr auto max(const auto &x, const auto &y, const auto &...args) { return max(x > y ? x : y, args...); }
constexpr bool chmax(auto &a, const auto &...args) {
  auto mx = max(args...);
  return mx > a ? (a = mx, true) : false;
}

constexpr auto min(const auto &x) { return x; }
constexpr auto min(const auto &x, const auto &y, const auto &...args) { return min(x < y ? x : y, args...); }
constexpr bool chmin(auto &a, const auto &...args) {
  auto mn = min(args...);
  return mn < a ? (a = mn, true) : false;
}

template <typename T = void>
constexpr auto sum(const R::input_range auto &v, auto &&...args) {
  if constexpr (std::is_void_v<T>) return std::reduce(all(v), R::range_value_t<decltype(v)>{}, args...);
  else return std::reduce(all(v), T{}, args...);
}

auto pop(vec_like auto &v) {
  auto p = std::move(v.back());
  v.pop_back();
  return p;
}

auto pop(auto &v)
  requires requires {
    v.top();
    v.pop();
  } {
  auto p = std::move(v.top());
  v.pop();
  return p;
}

template <typename T>
T pop(std::queue<T> &q) {
  T p = std::move(q.front());
  q.pop();
  return p;
}