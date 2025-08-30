---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: monoid/base.hpp
    title: monoid/base.hpp
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
  bundledCode: "#line 2 \"monoid/add.hpp\"\n\n#line 2 \"monoid/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct BaseMonoid {\n  using value_t = T;\n};\n#line 4 \"monoid/add.hpp\"\
    \n\ntemplate <typename T>\nstruct AddMonoid : BaseMonoid<T> {\n  static constexpr\
    \ T op(const T &x, const T &y) { return x + y; }\n  static constexpr T id() {\
    \ return 0; }\n};\n"
  code: "#pragma once\n\n#include \"monoid/base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ AddMonoid : BaseMonoid<T> {\n  static constexpr T op(const T &x, const T &y)\
    \ { return x + y; }\n  static constexpr T id() { return 0; }\n};"
  dependsOn:
  - monoid/base.hpp
  isVerificationFile: false
  path: monoid/add.hpp
  requiredBy: []
  timestamp: '2025-08-30 15:19:59+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/libchecker/point_add_range_sum.test.cpp
documentation_of: monoid/add.hpp
layout: document
redirect_from:
- /library/monoid/add.hpp
- /library/monoid/add.hpp.html
title: monoid/add.hpp
---
