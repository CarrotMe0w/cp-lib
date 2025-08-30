#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "main.hpp"

int main() {
  multi {
    dread(i128, a, b);
    writeln(a + b);
  }
}