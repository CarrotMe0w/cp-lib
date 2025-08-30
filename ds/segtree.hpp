#pragma once

#include "types.hpp"

template <typename M>
class SegTree {
  using T = M::value_t;

  int n, sz;
  vec<T> dat;

  void pushup(int u) { dat[u] = M::op(dat[u << 1], dat[u << 1 | 1]); }

public:
  SegTree(auto &&...args) { build(args...); }

  void build() { n = sz = 0; }
  void build(int l) {
    build(l, [&](int) { return M::id(); });
  }
  void build(const vec_like auto &a) {
    build(len(a), [&](int i) { return a[i]; });
  }
  void build(int l, std::invocable<int> auto &&f) {
    n = l;
    sz = 1 << lg<2>(n);

    dat.assign(sz << 1, M::id());
    fr (i, n) dat[i + sz] = f(i);
    fri (u, sz, 1) pushup(u);
  }

  void set(int u, const T x) {
    u += sz, dat[u] = x;
    while (u >>= 1) pushup(u);
  }

  void apply(int u, const T x) {
    u += sz, dat[u] = M::op(dat[u], x);
    while (u >>= 1) pushup(u);
  }

  auto data() const { return vec(dat.begin() + sz, dat.begin() + sz + n); }

  T query() const { return dat[1]; }
  T query(int u) const { return dat[u + sz]; }
  T query(int l, int r) const {
    T resl = M::id(), resr = M::id();
    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, dat[l++]);
      if (r & 1) resr = M::op(dat[--r], resr);
    }

    return M::op(resl, resr);
  }
};