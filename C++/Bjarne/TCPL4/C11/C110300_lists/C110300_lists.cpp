// C110300_lists.cpp 
#include <iostream>

struct S { int a, b; };
struct SS { double a, b; };

void f(S) {
  std::cout << "f() takes an S\n";
}

void g(S) {
  std::cout << "g() takes an S\n";
}

void g(SS) {
  std::cout << "g() takes an SS\n";
}

int main() {
  f({1,2});           // OK: call f(S{1,2})
  //g({1,2});           // Error: ambiguous
  g(S{1,2});          // OK: call g(S)
  g(SS{1,2});         // OK: call g(SS)
}
