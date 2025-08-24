---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: monoid/base.hpp
    title: monoid/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  timestamp: '2025-08-24 11:47:08+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: monoid/add.hpp
layout: document
redirect_from:
- /library/monoid/add.hpp
- /library/monoid/add.hpp.html
title: monoid/add.hpp
---
