#include "types.hpp"

template <typename T = void>
constexpr auto cumsum(const vec_like auto &v) {
  if constexpr (int n = len(v); std::is_void_v<T>) {
    vec<R::range_value_t<decltype(v)>> s(n + 1);
    fr (i, n) s[i + 1] = s[i] + v[i];
    return s;
  }
  else {
    vec<T> s(n + 1);
    fr (i, n) s[i + 1] = s[i] + v[i];
    return s;
  }
}