// C110302_qualified_lists.cpp 
#include <iostream>
#include <complex>

struct S { int a, b; };

void f() {
  S v{7,8};             // direct initialization of a variable
  v = S{7,8};           // assign using qualified list
  S* p = new S{7,8};    // construct on free store using qualified list
}

template<class T>
T square(T x) {
  return x * x;
}

void g(int i) {
  double d = square(double{(double)i});
  std::complex<double> z = square(std::complex<double>{(double)i});
}

int main() {
  f();
  g(3);
}
