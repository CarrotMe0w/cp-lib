#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "main.hpp"

int main() {
  multi {
    dread(i64, a, b);
    writeln(a + b);
  }
}