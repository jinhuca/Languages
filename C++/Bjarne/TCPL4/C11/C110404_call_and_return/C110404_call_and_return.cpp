// C110404_call_and_return.cpp 
#include <iostream>

auto minimum_lambda = [] {};

void h() {}
int f(int x) { return x + 12; }

void g(double y) {
  auto z = [&] { h(); };         // return type is void
  auto z0 = [&] { f(5); };       // return type is int
  auto z1 = [=](int x) { return x + y; };   // return type is double
  auto z2 = [y] {if(y) return 1; else return 2; };
  auto z3 = [y]() { return y ? 1 : 2; };    // return type is int
  auto z4 = [y]()->int {if(y) return 1; else return 2; };  // OK: explicit return type
}

int main() {
  g(2.2);
}
