// C120105_inline_functions.cpp 
#include <iostream>

inline int fac(int n) {
  return (n < 2) ? 1 : n * fac(n - 1);
}

int main() {
  int i = 5;
  std::cout << "fac(" << i << ") = " << fac(i);
}
