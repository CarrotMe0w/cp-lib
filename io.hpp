#include "types.hpp"

class IO {
public:
  bool eof = false;
  size_t prec = 6;
  strv sep = " ";

  IO() {
    char *ptr = table[0];
    fr (a, 10)
      fr (b, 10)
        fr (c, 10)
          fr (d, 10) *ptr++ = a + '0', *ptr++ = b + '0', *ptr++ = c + '0', *ptr++ = d + '0';
  }

  void seti(FILE *f) { in = f; }
  void seti(const str f) { in = fopen(f.c_str(), "r"); }
  void seto(FILE *f) { out = f; }
  void seto(const str f) { out = fopen(f.c_str(), "w"); }
  void setio(const str f, const str exti = ".in", const str exto = ".out") { seti(f + exti), seto(f + exto); }
  void setprec(const size_t p) { prec = p; }
  void setsep(const strv s) { sep = s; }

  char getchar() {
    if (iptr == eptr) {
      reload();
      if (iptr == eptr) return eof = true, EOF;
    }
    return *iptr++;
  }

  str getline() {
    str s;
    char c = getchar();
    while (c != '\n') s += c, c = getchar();

    if (s.back() == '\r') pop(s);
    return s;
  }

  void read(char &c) { c = getchar_skipws(); }
  void read(str &s) {
    s.clear();

    char c = getchar_skipws();
    while (c > ' ') s += c, c = getchar();
  }

  void read(signed_integer auto &x) {
    x = 0;
    bool neg = false;

    char c = getchar_skipws();
    if (c == '-') neg = true, c = getchar_skipws();
    while (c >= '0') x = x * 10 + c - '0', c = getchar();

    if (neg) x = -x;
  }

  void read(unsigned_integer auto &x) {
    x = 0;

    char c = getchar_skipws();
    while (c >= '0') x = x * 10 + c - '0', c = getchar();
  }

  void read(std::floating_point auto &x) {
    static str s;
    read(s);
    std::from_chars(s.begin().base(), s.end().base(), x);
  }

  template <typename T1, typename T2>
  void read(std::pair<T1, T2> &p) { read(p.first), read(p.second); }
  template <typename... Args>
  void read(std::tuple<Args...> &t) {
    std::apply([&](auto &...args) { (read(args), ...); }, t);
  }

  template <vec_like T>
  void read(T &v)
    requires (!std::is_same_v<R::range_value_t<T>, char>) {
    fre (x, v) read(x);
  }

  void flush() { fwrite(obuf, 1, optr - obuf, out), optr = obuf; }

  void write(const char c) {
    if (optr == obuf + BUF_SIZE) flush();
    *optr++ = c;
  }

  void write(const strv s) {
    fre (c, s) write(c);
  }

  void write(integer auto x) {
    if (obuf + BUF_SIZE - optr < TOS_SIZE) flush();

    if constexpr (signed_integer<decltype(x)>)
      if (x < 0) *optr++ = '-', x = -x;

    static char tos[TOS_SIZE + 10];
    char *sptr = tos + TOS_SIZE;
    for (; x >= 10000; x /= 10000) memcpy(sptr -= 4, table[x % 10000], 4);

    if (x >= 1000) {
      memcpy(optr, table[x], 4);
      optr += 4;
    }
    else if (x >= 100) {
      memcpy(optr, table[x] + 1, 3);
      optr += 3;
    }
    else if (x >= 10) {
      memcpy(optr, table[x] + 2, 2);
      optr += 2;
    }
    else *optr++ = x + '0';

    memcpy(optr, sptr, tos + TOS_SIZE - sptr);
    optr += tos + TOS_SIZE - sptr;
  }

  void write(const std::floating_point auto x) {
    static char tos[TOS_SIZE];
    size_t z = std::to_chars(all(tos), x, std::chars_format::fixed, prec).ptr - tos;

    if (R::end(obuf) - optr < z) flush();

    memcpy(optr, tos, z);
    optr += z;
  }

  template <typename T1, typename T2>
  void write(const std::pair<T1, T2> p) { write(p.first), write(sep), write(p.second); }
  void write(const std::tuple<>) {}
  template <typename... Args>
  void write(const std::tuple<Args...> t) {
    std::apply([&](auto &&x, auto &&...args) { write(x), ((write(sep), write(args)), ...); }, t);
  }

  template <vec_like T>
  void write(const T v)
    requires (!std::is_same_v<R::range_value_t<T>, char>) {
    if (len(v)) {
      write(v.front());
      for (int i = 1; i < len(v); i++) write(sep), write(v[i]);
    }
  }

  ~IO() { flush(); }

private:
  static constexpr size_t BUF_SIZE = 1 << 20, TOS_SIZE = 1 << 6;

  FILE *in = stdin, *out = stdout;
  char ibuf[BUF_SIZE + 10], obuf[BUF_SIZE + 10], *iptr = ibuf, *eptr = ibuf, *optr = obuf;
  char table[10000][4];

  void reload() { iptr = ibuf, eptr = ibuf + fread(ibuf, 1, BUF_SIZE, in); }

  char getchar_skipws() {
    char c;
    for (c = 0; c <= ' ' && c != EOF; c = getchar());
    return c;
  }
} io;

void read(auto &...args) { (io.read(FWD(args)), ...); }
template <typename T = int>
T read() {
  T x;
  read(x);
  return x;
}

void nwrite(auto &&...args) { (io.write(FWD(args)), ...); }
void nwriteln(auto &&...args) { nwrite(args..., '\n'); }
void write(auto &&...args) { nwrite(std::tuple(args...)); }
void writeln(auto &&...args) { nwrite(std::tuple(args...), '\n'); }

#define dread(T, ...) \
  T __VA_ARGS__;      \
  read(__VA_ARGS__)
#define dreadv(T, a, ...)        \
  auto a = dvec<T>(__VA_ARGS__); \
  read(a)

#define multi for (int _tc = read(), testcase = 1; testcase <= _tc; testcase++)

void yes(bool b = true) { nwriteln(b ? "yes" : "no"); }
void no(bool b = true) { nwriteln(b ? "no" : "yes"); }
void Yes(bool b = true) { nwriteln(b ? "Yes" : "No"); }
void No(bool b = true) { nwriteln(b ? "No" : "Yes"); }
void YES(bool b = true) { nwriteln(b ? "YES" : "NO"); }
void NO(bool b = true) { nwriteln(b ? "NO" : "YES"); }