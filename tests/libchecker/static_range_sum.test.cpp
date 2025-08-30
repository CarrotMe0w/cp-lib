#include "main.hpp"
#include "misc/cumsum.hpp"

int main() {
  dread(int, n, q);
  dreadv(int, a, n);

  auto s = cumsum<i64>(a);

  fr (q) {
    dread(int, l, r);
    writeln(s[r] - s[l]);
  }
}