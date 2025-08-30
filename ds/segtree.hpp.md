---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: func.hpp
    title: func.hpp
  - icon: ':question:'
    path: types.hpp
    title: types.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/libchecker/point_add_range_sum.test.cpp
    title: tests/libchecker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/segtree.hpp\"\n\n#line 2 \"types.hpp\"\n\n#line 2 \"\
    func.hpp\"\n\n#include <bits/stdc++.h>\n\nusing namespace std::literals;\nnamespace\
    \ R = std::ranges;\nnamespace V = std::views;\n\n#line 10 \"func.hpp\"\n\n#define\
    \ CONCAT0(a, b) a##b\n#define CONCAT(a, b) CONCAT0(a, b)\n\n#define GET1(a, ...)\
    \ a\n#define GET2(a, b, ...) b\n#define GET3(a, b, c, ...) c\n#define GET4(a,\
    \ b, c, d, ...) d\n#define GET5(a, b, c, d, e, ...) e\n#define GET6(a, b, c, d,\
    \ e, f, ...) f\n#define GET9(a, b, c, d, e, f, g, h, i, ...) i\n#define GET_LAST(...)\
    \ CONCAT(GET, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n#define DROP_LAST1(a)\n#define\
    \ DROP_LAST2(a, b) a\n#define DROP_LAST3(a, b, c) a, b\n#define DROP_LAST4(a,\
    \ b, c, d) a, b, c\n#define DROP_LAST5(a, b, c, d, e) a, b, c, d\n#define DROP_LAST(...)\
    \ CONCAT(DROP_LAST, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n\n#define ARGSNUM(...)\
    \ GET6(__VA_ARGS__ __VA_OPT__(, ) 5, 4, 3, 2, 1, 0)\n\n#define FR0() while (true)\n\
    #define FR1(a) FR2(_, a)\n#define FR2(i, a) for (std::decay_t<decltype(a)> i =\
    \ 0; i < (a); i++)\n#define FR3(i, a, b) for (std::common_type_t<decltype(a),\
    \ decltype(b)> i = (a); i < (b); i++)\n#define FR4(i, a, b, c) for (std::common_type_t<decltype(a),\
    \ decltype(b)> i = (a); i < (b); i++)\n#define fr(...) CONCAT(FR, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n\
    #define FRI2(i, a) for (auto i = (a); i--;)\n#define FRI3(i, b, a) for (auto i\
    \ = (b); i-- > (a);)\n#define fri(...) CONCAT(FRI, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n\
    \n#define FRE1(a) a\n#define FRE2(...) [__VA_ARGS__]\n#define FRE_ARGS(...) GET5(__VA_ARGS__,\
    \ FRE2, FRE2, FRE2, FRE1)(__VA_ARGS__)\n#define fre(...) for (auto &&FRE_ARGS(DROP_LAST(__VA_ARGS__))\
    \ : GET_LAST(__VA_ARGS__))\n\n#define all(a) R::begin(a), R::end(a)\n\n#define\
    \ FWD(x) std::forward<decltype(x)>(x)\n\n#define j0 __j0\n#define j1 __j1\n#define\
    \ y0 __y0\n#define y1 __y1\n\n#define exec _exec | [&]\nstruct exec_t {\n  void\
    \ operator|(auto &&func) { func(); }\n} _exec;\n\nconstexpr auto floordiv(auto\
    \ &&x, auto &&y) { return x / y - (x % y && x < 0 ^ y < 0); }\nconstexpr auto\
    \ ceildiv(auto &&x, auto &&y) { return floordiv(x + y - 1, y); }\nconstexpr auto\
    \ divmod(auto &&x, auto &&y) {\n  auto &&d = floordiv(x, y);\n  return std::pair{d,\
    \ x - y * d};\n}\n\ntemplate <auto base = 10>\nconstexpr int lg(auto &&n) {\n\
    \  if constexpr (base == 2) return n <= 2 ? 1 : std::bit_width<to_unsigned_t<decltype(n\
    \ - 1)>>(n - 1);\n  return n <= base ? 1 : lg<base>(n / base) + 1;\n}\ntemplate\
    \ <typename T = u64>\nconstexpr T pw(const auto base, auto &&n) { return n ==\
    \ 0 ? 1 : pw<T>(base, n - 1) * base; }\ntemplate <typename T>\nconstexpr T truncate(const\
    \ T &&n) {\n  T p = pw<T>(10, lg(n) - 1);\n  return n / p * p;\n}\n\ntemplate\
    \ <typename T>\nconstexpr T inf = truncate(std::numeric_limits<T>::max() >> 1);\n\
    template <>\nconstexpr f64 inf<f64> = inf<u64>;\ntemplate <>\nconstexpr fld inf<fld>\
    \ = inf<u64>;\n\ntemplate <typename T = int>\nauto dvec(size_t n) { return vec<T>(n);\
    \ }\ntemplate <typename T = int>\nauto dvec(size_t n, auto &&...args) { return\
    \ vec(n, dvec<T>(args...)); }\ntemplate <typename T = int>\nauto fvec(size_t n,\
    \ T x) { return vec<T>(n, x); }\ntemplate <typename T = int>\nauto fvec(size_t\
    \ n, auto &&...args)\n  requires (sizeof...(args) >= 2) { return vec(n, fvec<T>(args...));\
    \ }\n\nconstexpr int len(auto &&c) { return R::size(c); }\n\nconstexpr int lb(R::forward_range\
    \ auto &&c, const auto &val, auto... args) {\n  return R::lower_bound(c, val,\
    \ args...) - R::begin(c);\n}\nconstexpr int ub(R::forward_range auto &&c, const\
    \ auto &val, auto... args) {\n  return R::upper_bound(c, val, args...) - R::begin(c);\n\
    }\n\nconstexpr auto max(const auto &x) { return x; }\nconstexpr auto max(const\
    \ auto &x, const auto &y, const auto &...args) { return max(x > y ? x : y, args...);\
    \ }\nconstexpr bool chmax(auto &a, const auto &...args) {\n  auto mx = max(args...);\n\
    \  return mx > a ? (a = mx, true) : false;\n}\n\nconstexpr auto min(const auto\
    \ &x) { return x; }\nconstexpr auto min(const auto &x, const auto &y, const auto\
    \ &...args) { return min(x < y ? x : y, args...); }\nconstexpr bool chmin(auto\
    \ &a, const auto &...args) {\n  auto mn = min(args...);\n  return mn < a ? (a\
    \ = mn, true) : false;\n}\n\ntemplate <typename T = void>\nconstexpr auto sum(const\
    \ R::input_range auto &v, auto &&...args) {\n  if constexpr (std::is_void_v<T>)\
    \ return std::reduce(all(v), R::range_value_t<decltype(v)>{}, args...);\n  else\
    \ return std::reduce(all(v), T{}, args...);\n}\n\nauto pop(vec_like auto &v) {\n\
    \  auto p = std::move(v.back());\n  v.pop_back();\n  return p;\n}\n\nauto pop(auto\
    \ &v)\n  requires requires {\n    v.top();\n    v.pop();\n  } {\n  auto p = std::move(v.top());\n\
    \  v.pop();\n  return p;\n}\n\ntemplate <typename T>\nT pop(std::queue<T> &q)\
    \ {\n  T p = std::move(q.front());\n  q.pop();\n  return p;\n}\n#line 4 \"types.hpp\"\
    \n\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128;\nusing u128 = unsigned __int128;\nusing f32 = float;\n\
    using f64 = double;\nusing fld = long double;\n\ntemplate <typename T>\nusing\
    \ vec = std::vector<T>;\ntemplate <typename T>\nusing vec2d = vec<vec<T>>;\ntemplate\
    \ <typename T>\nusing vec3d = vec<vec2d<T>>;\nusing veci = vec<int>;\nusing vec2i\
    \ = vec2d<int>;\nusing vec3i = vec3d<int>;\n\nusing str = std::string;\nusing\
    \ strv = std::string_view;\n\ntemplate <typename T>\nusing gp_queue = std::priority_queue<T>;\n\
    template <typename T>\nusing lp_queue = std::priority_queue<T, vec<T>, std::greater<>>;\n\
    \ntemplate <typename T>\nstruct to_unsigned : std::make_unsigned<T> {};\ntemplate\
    \ <>\nstruct to_unsigned<i128> {\n  using type = u128;\n};\ntemplate <typename\
    \ T>\nusing to_unsigned_t = to_unsigned<T>::type;\n\ntemplate <typename T>\nconcept\
    \ signed_integer = std::signed_integral<T> || std::is_same_v<T, i128>;\ntemplate\
    \ <typename T>\nconcept unsigned_integer = std::unsigned_integral<T> || std::is_same_v<T,\
    \ u128>;\ntemplate <typename T>\nconcept integer = signed_integer<T> || unsigned_integer<T>;\n\
    template <typename T>\nconcept vec_like = R::random_access_range<T> && R::sized_range<T>;\n\
    template <typename T>\nconcept vec2d_like = vec_like<T> && vec_like<R::range_value_t<T>>;\n\
    #line 4 \"ds/segtree.hpp\"\n\ntemplate <typename M>\nclass SegTree {\n  using\
    \ T = M::value_t;\n\n  int n, sz;\n  vec<T> dat;\n\n  void pushup(int u) { dat[u]\
    \ = M::op(dat[u << 1], dat[u << 1 | 1]); }\n\npublic:\n  SegTree(auto &&...args)\
    \ { build(args...); }\n\n  void build() { n = sz = 0; }\n  void build(int l) {\n\
    \    build(l, [&](int) { return M::id(); });\n  }\n  void build(const vec_like\
    \ auto &a) {\n    build(len(a), [&](int i) { return a[i]; });\n  }\n  void build(int\
    \ l, std::invocable<int> auto &&f) {\n    n = l;\n    sz = 1 << lg<2>(n);\n\n\
    \    dat.assign(sz << 1, M::id());\n    fr (i, n) dat[i + sz] = f(i);\n    fri\
    \ (u, sz, 1) pushup(u);\n  }\n\n  void set(int u, const T x) {\n    u += sz, dat[u]\
    \ = x;\n    while (u >>= 1) pushup(u);\n  }\n\n  void apply(int u, const T x)\
    \ {\n    u += sz, dat[u] = M::op(dat[u], x);\n    while (u >>= 1) pushup(u);\n\
    \  }\n\n  auto data() const { return vec(dat.begin() + sz, dat.begin() + sz +\
    \ n); }\n\n  T query() const { return dat[1]; }\n  T query(int u) const { return\
    \ dat[u + sz]; }\n  T query(int l, int r) const {\n    T resl = M::id(), resr\
    \ = M::id();\n    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) resl = M::op(resl, dat[l++]);\n      if (r & 1) resr = M::op(dat[--r],\
    \ resr);\n    }\n\n    return M::op(resl, resr);\n  }\n};\n"
  code: "#pragma once\n\n#include \"types.hpp\"\n\ntemplate <typename M>\nclass SegTree\
    \ {\n  using T = M::value_t;\n\n  int n, sz;\n  vec<T> dat;\n\n  void pushup(int\
    \ u) { dat[u] = M::op(dat[u << 1], dat[u << 1 | 1]); }\n\npublic:\n  SegTree(auto\
    \ &&...args) { build(args...); }\n\n  void build() { n = sz = 0; }\n  void build(int\
    \ l) {\n    build(l, [&](int) { return M::id(); });\n  }\n  void build(const vec_like\
    \ auto &a) {\n    build(len(a), [&](int i) { return a[i]; });\n  }\n  void build(int\
    \ l, std::invocable<int> auto &&f) {\n    n = l;\n    sz = 1 << lg<2>(n);\n\n\
    \    dat.assign(sz << 1, M::id());\n    fr (i, n) dat[i + sz] = f(i);\n    fri\
    \ (u, sz, 1) pushup(u);\n  }\n\n  void set(int u, const T x) {\n    u += sz, dat[u]\
    \ = x;\n    while (u >>= 1) pushup(u);\n  }\n\n  void apply(int u, const T x)\
    \ {\n    u += sz, dat[u] = M::op(dat[u], x);\n    while (u >>= 1) pushup(u);\n\
    \  }\n\n  auto data() const { return vec(dat.begin() + sz, dat.begin() + sz +\
    \ n); }\n\n  T query() const { return dat[1]; }\n  T query(int u) const { return\
    \ dat[u + sz]; }\n  T query(int l, int r) const {\n    T resl = M::id(), resr\
    \ = M::id();\n    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) resl = M::op(resl, dat[l++]);\n      if (r & 1) resr = M::op(dat[--r],\
    \ resr);\n    }\n\n    return M::op(resl, resr);\n  }\n};"
  dependsOn:
  - types.hpp
  - func.hpp
  isVerificationFile: false
  path: ds/segtree.hpp
  requiredBy: []
  timestamp: '2025-08-30 15:19:59+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/libchecker/point_add_range_sum.test.cpp
documentation_of: ds/segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree.hpp
- /library/ds/segtree.hpp.html
title: ds/segtree.hpp
---
