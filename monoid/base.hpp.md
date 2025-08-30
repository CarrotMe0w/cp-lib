---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: monoid/add.hpp
    title: monoid/add.hpp
  - icon: ':warning:'
    path: monoid/max.hpp
    title: monoid/max.hpp
  - icon: ':warning:'
    path: monoid/min.hpp
    title: monoid/min.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/libchecker/point_add_range_sum.test.cpp
    title: tests/libchecker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"monoid/base.hpp\"\n\ntemplate <typename T>\nstruct BaseMonoid\
    \ {\n  using value_t = T;\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct BaseMonoid {\n  using value_t\
    \ = T;\n};"
  dependsOn: []
  isVerificationFile: false
  path: monoid/base.hpp
  requiredBy:
  - monoid/add.hpp
  - monoid/max.hpp
  - monoid/min.hpp
  timestamp: '2025-08-30 15:19:59+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/libchecker/point_add_range_sum.test.cpp
documentation_of: monoid/base.hpp
layout: document
redirect_from:
- /library/monoid/base.hpp
- /library/monoid/base.hpp.html
title: monoid/base.hpp
---
