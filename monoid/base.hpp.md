---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: monoid/add.hpp
    title: monoid/add.hpp
  - icon: ':warning:'
    path: monoid/max.hpp
    title: monoid/max.hpp
  - icon: ':warning:'
    path: monoid/min.hpp
    title: monoid/min.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  timestamp: '2025-08-24 11:47:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/base.hpp
layout: document
redirect_from:
- /library/monoid/base.hpp
- /library/monoid/base.hpp.html
title: monoid/base.hpp
---
