#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "main.hpp"
#include "ds/segtree.hpp"
#include "monoid/add.hpp"

int main() {
  dread(int, n, q);
  dreadv(int, a, n);

  SegTree<AddMonoid<i64>> seg(a);

  fr (q) {
    dread(int, op, u, v);
    if (op == 0) seg.apply(u, v);
    else writeln(seg.query(u, v));
  }
}