---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: func.hpp
    title: func.hpp
  - icon: ':question:'
    path: types.hpp
    title: types.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: main.hpp
    title: main.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/libchecker/aplusb.test.cpp
    title: tests/libchecker/aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/libchecker/many_aplusb.test.cpp
    title: tests/libchecker/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/libchecker/many_aplusb_128bit.test.cpp
    title: tests/libchecker/many_aplusb_128bit.test.cpp
  - icon: ':x:'
    path: tests/libchecker/point_add_range_sum.test.cpp
    title: tests/libchecker/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: tests/libchecker/static_range_sum.test.cpp
    title: tests/libchecker/static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"types.hpp\"\n\n#line 2 \"func.hpp\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std::literals;\nnamespace R = std::ranges;\nnamespace V = std::views;\n\
    \n#line 10 \"func.hpp\"\n\n#define CONCAT0(a, b) a##b\n#define CONCAT(a, b) CONCAT0(a,\
    \ b)\n\n#define GET1(a, ...) a\n#define GET2(a, b, ...) b\n#define GET3(a, b,\
    \ c, ...) c\n#define GET4(a, b, c, d, ...) d\n#define GET5(a, b, c, d, e, ...)\
    \ e\n#define GET6(a, b, c, d, e, f, ...) f\n#define GET9(a, b, c, d, e, f, g,\
    \ h, i, ...) i\n#define GET_LAST(...) CONCAT(GET, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n\
    #define DROP_LAST1(a)\n#define DROP_LAST2(a, b) a\n#define DROP_LAST3(a, b, c)\
    \ a, b\n#define DROP_LAST4(a, b, c, d) a, b, c\n#define DROP_LAST5(a, b, c, d,\
    \ e) a, b, c, d\n#define DROP_LAST(...) CONCAT(DROP_LAST, ARGSNUM(__VA_ARGS__))(__VA_ARGS__)\n\
    \n#define ARGSNUM(...) GET6(__VA_ARGS__ __VA_OPT__(, ) 5, 4, 3, 2, 1, 0)\n\n#define\
    \ FR0() while (true)\n#define FR1(a) FR2(_, a)\n#define FR2(i, a) for (std::decay_t<decltype(a)>\
    \ i = 0; i < (a); i++)\n#define FR3(i, a, b) for (std::common_type_t<decltype(a),\
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
    #line 2 \"io.hpp\"\n\nclass IO {\npublic:\n  bool eof = false;\n  size_t prec\
    \ = 6;\n  strv sep = \" \";\n\n  IO() {\n    char *ptr = table[0];\n    fr (a,\
    \ 10)\n      fr (b, 10)\n        fr (c, 10)\n          fr (d, 10) *ptr++ = a +\
    \ '0', *ptr++ = b + '0', *ptr++ = c + '0', *ptr++ = d + '0';\n  }\n\n  void seti(FILE\
    \ *f) { in = f; }\n  void seti(const str f) { in = fopen(f.c_str(), \"r\"); }\n\
    \  void seto(FILE *f) { out = f; }\n  void seto(const str f) { out = fopen(f.c_str(),\
    \ \"w\"); }\n  void setio(const str f, const str exti = \".in\", const str exto\
    \ = \".out\") { seti(f + exti), seto(f + exto); }\n  void setprec(const size_t\
    \ p) { prec = p; }\n  void setsep(const strv s) { sep = s; }\n\n  char getchar()\
    \ {\n    if (iptr == eptr) {\n      reload();\n      if (iptr == eptr) return\
    \ eof = true, EOF;\n    }\n    return *iptr++;\n  }\n\n  str getline() {\n   \
    \ str s;\n    char c = getchar();\n    while (c != '\\n') s += c, c = getchar();\n\
    \n    if (s.back() == '\\r') pop(s);\n    return s;\n  }\n\n  void read(char &c)\
    \ { c = getchar_skipws(); }\n  void read(str &s) {\n    s.clear();\n\n    char\
    \ c = getchar_skipws();\n    while (c > ' ') s += c, c = getchar();\n  }\n\n \
    \ void read(signed_integer auto &x) {\n    x = 0;\n    bool neg = false;\n\n \
    \   char c = getchar_skipws();\n    if (c == '-') neg = true, c = getchar_skipws();\n\
    \    while (c >= '0') x = x * 10 + c - '0', c = getchar();\n\n    if (neg) x =\
    \ -x;\n  }\n\n  void read(unsigned_integer auto &x) {\n    x = 0;\n\n    char\
    \ c = getchar_skipws();\n    while (c >= '0') x = x * 10 + c - '0', c = getchar();\n\
    \  }\n\n  void read(std::floating_point auto &x) {\n    static str s;\n    read(s);\n\
    \    std::from_chars(s.begin().base(), s.end().base(), x);\n  }\n\n  template\
    \ <typename T1, typename T2>\n  void read(std::pair<T1, T2> &p) { read(p.first),\
    \ read(p.second); }\n  template <typename... Args>\n  void read(std::tuple<Args...>\
    \ &t) {\n    std::apply([&](auto &...args) { (read(args), ...); }, t);\n  }\n\n\
    \  template <vec_like T>\n  void read(T &v)\n    requires (!std::is_same_v<R::range_value_t<T>,\
    \ char>) {\n    fre (x, v) read(x);\n  }\n\n  void flush() { fwrite(obuf, 1, optr\
    \ - obuf, out), optr = obuf; }\n\n  void write(const char c) {\n    if (optr ==\
    \ obuf + BUF_SIZE) flush();\n    *optr++ = c;\n  }\n\n  void write(const strv\
    \ s) {\n    fre (c, s) write(c);\n  }\n\n  void write(integer auto x) {\n    if\
    \ (obuf + BUF_SIZE - optr < TOS_SIZE) flush();\n\n    if constexpr (signed_integer<decltype(x)>)\n\
    \      if (x < 0) *optr++ = '-', x = -x;\n\n    static char tos[TOS_SIZE + 10];\n\
    \    char *sptr = tos + TOS_SIZE;\n    for (; x >= 10000; x /= 10000) memcpy(sptr\
    \ -= 4, table[x % 10000], 4);\n\n    if (x >= 1000) {\n      memcpy(optr, table[x],\
    \ 4);\n      optr += 4;\n    }\n    else if (x >= 100) {\n      memcpy(optr, table[x]\
    \ + 1, 3);\n      optr += 3;\n    }\n    else if (x >= 10) {\n      memcpy(optr,\
    \ table[x] + 2, 2);\n      optr += 2;\n    }\n    else *optr++ = x + '0';\n\n\
    \    memcpy(optr, sptr, tos + TOS_SIZE - sptr);\n    optr += tos + TOS_SIZE -\
    \ sptr;\n  }\n\n  void write(const std::floating_point auto x) {\n    static char\
    \ tos[TOS_SIZE];\n    size_t z = std::to_chars(all(tos), x, std::chars_format::fixed,\
    \ prec).ptr - tos;\n\n    if (R::end(obuf) - optr < z) flush();\n\n    memcpy(optr,\
    \ tos, z);\n    optr += z;\n  }\n\n  template <typename T1, typename T2>\n  void\
    \ write(const std::pair<T1, T2> p) { write(p.first), write(sep), write(p.second);\
    \ }\n  void write(const std::tuple<>) {}\n  template <typename... Args>\n  void\
    \ write(const std::tuple<Args...> t) {\n    std::apply([&](auto &&x, auto &&...args)\
    \ { write(x), ((write(sep), write(args)), ...); }, t);\n  }\n\n  template <vec_like\
    \ T>\n  void write(const T v)\n    requires (!std::is_same_v<R::range_value_t<T>,\
    \ char>) {\n    if (len(v)) {\n      write(v.front());\n      for (int i = 1;\
    \ i < len(v); i++) write(sep), write(v[i]);\n    }\n  }\n\n  ~IO() { flush();\
    \ }\n\nprivate:\n  static constexpr size_t BUF_SIZE = 1 << 20, TOS_SIZE = 1 <<\
    \ 6;\n\n  FILE *in = stdin, *out = stdout;\n  char ibuf[BUF_SIZE + 10], obuf[BUF_SIZE\
    \ + 10], *iptr = ibuf, *eptr = ibuf, *optr = obuf;\n  char table[10000][4];\n\n\
    \  void reload() { iptr = ibuf, eptr = ibuf + fread(ibuf, 1, BUF_SIZE, in); }\n\
    \n  char getchar_skipws() {\n    char c;\n    for (c = 0; c <= ' ' && c != EOF;\
    \ c = getchar());\n    return c;\n  }\n} io;\n\nvoid read(auto &...args) { (io.read(FWD(args)),\
    \ ...); }\ntemplate <typename T = int>\nT read() {\n  T x;\n  read(x);\n  return\
    \ x;\n}\n\nvoid nwrite(auto &&...args) { (io.write(FWD(args)), ...); }\nvoid nwriteln(auto\
    \ &&...args) { nwrite(args..., '\\n'); }\nvoid write(auto &&...args) { nwrite(std::tuple(args...));\
    \ }\nvoid writeln(auto &&...args) { nwrite(std::tuple(args...), '\\n'); }\n\n\
    #define dread(T, ...) \\\n  T __VA_ARGS__;      \\\n  read(__VA_ARGS__)\n#define\
    \ dreadv(T, a, ...)        \\\n  auto a = dvec<T>(__VA_ARGS__); \\\n  read(a)\n\
    \n#define multi for (int _tc = read(), testcase = 1; testcase <= _tc; testcase++)\n\
    \nvoid yes(bool b = true) { nwriteln(b ? \"yes\" : \"no\"); }\nvoid no(bool b\
    \ = true) { nwriteln(b ? \"no\" : \"yes\"); }\nvoid Yes(bool b = true) { nwriteln(b\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool b = true) { nwriteln(b ? \"No\" : \"Yes\"\
    ); }\nvoid YES(bool b = true) { nwriteln(b ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ b = true) { nwriteln(b ? \"NO\" : \"YES\"); }\n"
  code: "#include \"types.hpp\"\n\nclass IO {\npublic:\n  bool eof = false;\n  size_t\
    \ prec = 6;\n  strv sep = \" \";\n\n  IO() {\n    char *ptr = table[0];\n    fr\
    \ (a, 10)\n      fr (b, 10)\n        fr (c, 10)\n          fr (d, 10) *ptr++ =\
    \ a + '0', *ptr++ = b + '0', *ptr++ = c + '0', *ptr++ = d + '0';\n  }\n\n  void\
    \ seti(FILE *f) { in = f; }\n  void seti(const str f) { in = fopen(f.c_str(),\
    \ \"r\"); }\n  void seto(FILE *f) { out = f; }\n  void seto(const str f) { out\
    \ = fopen(f.c_str(), \"w\"); }\n  void setio(const str f, const str exti = \"\
    .in\", const str exto = \".out\") { seti(f + exti), seto(f + exto); }\n  void\
    \ setprec(const size_t p) { prec = p; }\n  void setsep(const strv s) { sep = s;\
    \ }\n\n  char getchar() {\n    if (iptr == eptr) {\n      reload();\n      if\
    \ (iptr == eptr) return eof = true, EOF;\n    }\n    return *iptr++;\n  }\n\n\
    \  str getline() {\n    str s;\n    char c = getchar();\n    while (c != '\\n')\
    \ s += c, c = getchar();\n\n    if (s.back() == '\\r') pop(s);\n    return s;\n\
    \  }\n\n  void read(char &c) { c = getchar_skipws(); }\n  void read(str &s) {\n\
    \    s.clear();\n\n    char c = getchar_skipws();\n    while (c > ' ') s += c,\
    \ c = getchar();\n  }\n\n  void read(signed_integer auto &x) {\n    x = 0;\n \
    \   bool neg = false;\n\n    char c = getchar_skipws();\n    if (c == '-') neg\
    \ = true, c = getchar_skipws();\n    while (c >= '0') x = x * 10 + c - '0', c\
    \ = getchar();\n\n    if (neg) x = -x;\n  }\n\n  void read(unsigned_integer auto\
    \ &x) {\n    x = 0;\n\n    char c = getchar_skipws();\n    while (c >= '0') x\
    \ = x * 10 + c - '0', c = getchar();\n  }\n\n  void read(std::floating_point auto\
    \ &x) {\n    static str s;\n    read(s);\n    std::from_chars(s.begin().base(),\
    \ s.end().base(), x);\n  }\n\n  template <typename T1, typename T2>\n  void read(std::pair<T1,\
    \ T2> &p) { read(p.first), read(p.second); }\n  template <typename... Args>\n\
    \  void read(std::tuple<Args...> &t) {\n    std::apply([&](auto &...args) { (read(args),\
    \ ...); }, t);\n  }\n\n  template <vec_like T>\n  void read(T &v)\n    requires\
    \ (!std::is_same_v<R::range_value_t<T>, char>) {\n    fre (x, v) read(x);\n  }\n\
    \n  void flush() { fwrite(obuf, 1, optr - obuf, out), optr = obuf; }\n\n  void\
    \ write(const char c) {\n    if (optr == obuf + BUF_SIZE) flush();\n    *optr++\
    \ = c;\n  }\n\n  void write(const strv s) {\n    fre (c, s) write(c);\n  }\n\n\
    \  void write(integer auto x) {\n    if (obuf + BUF_SIZE - optr < TOS_SIZE) flush();\n\
    \n    if constexpr (signed_integer<decltype(x)>)\n      if (x < 0) *optr++ = '-',\
    \ x = -x;\n\n    static char tos[TOS_SIZE + 10];\n    char *sptr = tos + TOS_SIZE;\n\
    \    for (; x >= 10000; x /= 10000) memcpy(sptr -= 4, table[x % 10000], 4);\n\n\
    \    if (x >= 1000) {\n      memcpy(optr, table[x], 4);\n      optr += 4;\n  \
    \  }\n    else if (x >= 100) {\n      memcpy(optr, table[x] + 1, 3);\n      optr\
    \ += 3;\n    }\n    else if (x >= 10) {\n      memcpy(optr, table[x] + 2, 2);\n\
    \      optr += 2;\n    }\n    else *optr++ = x + '0';\n\n    memcpy(optr, sptr,\
    \ tos + TOS_SIZE - sptr);\n    optr += tos + TOS_SIZE - sptr;\n  }\n\n  void write(const\
    \ std::floating_point auto x) {\n    static char tos[TOS_SIZE];\n    size_t z\
    \ = std::to_chars(all(tos), x, std::chars_format::fixed, prec).ptr - tos;\n\n\
    \    if (R::end(obuf) - optr < z) flush();\n\n    memcpy(optr, tos, z);\n    optr\
    \ += z;\n  }\n\n  template <typename T1, typename T2>\n  void write(const std::pair<T1,\
    \ T2> p) { write(p.first), write(sep), write(p.second); }\n  void write(const\
    \ std::tuple<>) {}\n  template <typename... Args>\n  void write(const std::tuple<Args...>\
    \ t) {\n    std::apply([&](auto &&x, auto &&...args) { write(x), ((write(sep),\
    \ write(args)), ...); }, t);\n  }\n\n  template <vec_like T>\n  void write(const\
    \ T v)\n    requires (!std::is_same_v<R::range_value_t<T>, char>) {\n    if (len(v))\
    \ {\n      write(v.front());\n      for (int i = 1; i < len(v); i++) write(sep),\
    \ write(v[i]);\n    }\n  }\n\n  ~IO() { flush(); }\n\nprivate:\n  static constexpr\
    \ size_t BUF_SIZE = 1 << 20, TOS_SIZE = 1 << 6;\n\n  FILE *in = stdin, *out =\
    \ stdout;\n  char ibuf[BUF_SIZE + 10], obuf[BUF_SIZE + 10], *iptr = ibuf, *eptr\
    \ = ibuf, *optr = obuf;\n  char table[10000][4];\n\n  void reload() { iptr = ibuf,\
    \ eptr = ibuf + fread(ibuf, 1, BUF_SIZE, in); }\n\n  char getchar_skipws() {\n\
    \    char c;\n    for (c = 0; c <= ' ' && c != EOF; c = getchar());\n    return\
    \ c;\n  }\n} io;\n\nvoid read(auto &...args) { (io.read(FWD(args)), ...); }\n\
    template <typename T = int>\nT read() {\n  T x;\n  read(x);\n  return x;\n}\n\n\
    void nwrite(auto &&...args) { (io.write(FWD(args)), ...); }\nvoid nwriteln(auto\
    \ &&...args) { nwrite(args..., '\\n'); }\nvoid write(auto &&...args) { nwrite(std::tuple(args...));\
    \ }\nvoid writeln(auto &&...args) { nwrite(std::tuple(args...), '\\n'); }\n\n\
    #define dread(T, ...) \\\n  T __VA_ARGS__;      \\\n  read(__VA_ARGS__)\n#define\
    \ dreadv(T, a, ...)        \\\n  auto a = dvec<T>(__VA_ARGS__); \\\n  read(a)\n\
    \n#define multi for (int _tc = read(), testcase = 1; testcase <= _tc; testcase++)\n\
    \nvoid yes(bool b = true) { nwriteln(b ? \"yes\" : \"no\"); }\nvoid no(bool b\
    \ = true) { nwriteln(b ? \"no\" : \"yes\"); }\nvoid Yes(bool b = true) { nwriteln(b\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool b = true) { nwriteln(b ? \"No\" : \"Yes\"\
    ); }\nvoid YES(bool b = true) { nwriteln(b ? \"YES\" : \"NO\"); }\nvoid NO(bool\
    \ b = true) { nwriteln(b ? \"NO\" : \"YES\"); }"
  dependsOn:
  - types.hpp
  - func.hpp
  isVerificationFile: false
  path: io.hpp
  requiredBy:
  - main.hpp
  timestamp: '2025-08-30 15:19:59+08:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/libchecker/many_aplusb_128bit.test.cpp
  - tests/libchecker/aplusb.test.cpp
  - tests/libchecker/static_range_sum.test.cpp
  - tests/libchecker/many_aplusb.test.cpp
  - tests/libchecker/point_add_range_sum.test.cpp
documentation_of: io.hpp
layout: document
redirect_from:
- /library/io.hpp
- /library/io.hpp.html
title: io.hpp
---
