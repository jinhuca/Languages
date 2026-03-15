// C12010601_constexpr_and_references.cpp 
#include <iostream>

constexpr int ftbl[]{0, 1, 1, 2, 3, 5, 8, 13};
constexpr int fib(int n) {
  return (n < sizeof(ftbl) / sizeof(*ftbl)) ? ftbl[n] : fib(n - 2) + fib(n - 1);
}

constexpr const int* addr(const int& r) { return &r; }    // OK

void g() {
  for(int i = 0; i != 12; ++i)
    std::cout << fib(i) << ' ';
  std::cout << '\n';
}

void f() {
  static const int x = 5;
  constexpr const int* p1 = addr(x);      // OK
  constexpr int xx = *p1;                 // OK

  static int y;
  constexpr const int* p2 = addr(y);      // OK
  // constexpr int yy = *p2;              // error: attempt to read a variable

  // constexpr const int* tp = addr(5);      // error: address of temporary
}

int main() {
  g();
  f();
}
