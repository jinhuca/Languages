// C120106_constexpr_functions.cpp 
#include <iostream>

constexpr int fac(int n) {
  return (n > 1) ? n * fac(n - 1) : 1;
}

void use_constexpr_function(int n) {
  int f5 = fac(5);                  // may be evaluated at compile time
  int fn = fac(n);                  // evaluated at run time (n is a variable)

  constexpr int f6 = fac(6);        // must be evaluated at compile time
  // constexpr int fnn = fac(n);    // error: can't guarantee compile-time evaluation (n is a variable)

  int i1 = 8;
  // constexpr int f8 = fac(i1);    // error: i1 must be constexpr and evaluated at compile time

  constexpr int i2 = 7;
  constexpr int f7 = fac(i2);    // OK: i2 is a constexpr and evaluated at compile time
  constexpr int f9 = fac(9);    // must be evaluated at compile time

  char a[fac(4)];                   // OK: array bounds must be constants and fac() is constexpr
  // char a2[fac(n)];               // error: array bounds must be constants and n is a variable
}

int glob;               // a global variable

constexpr void bad1(int a) {
  glob = a;
}

constexpr int bad2(int a) {
  if(a >= 0) return a;
  else return -a;
}

int main() {
  use_constexpr_function(5);
  bad1(4);
  bad2(5);
}
