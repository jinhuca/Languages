// C06030502_initializer_lists.cpp 
#include <iostream>
#include <string>
#include <complex>
#include <numbers>
#include <vector>

struct S { int x; std::string s; };

void f() {
  int a[] = {1,2};       // a is an array of 2 ints, initialized by copying the elements of the initializer list.
  S s = {1, "Helios"};  // s is an S, initialized by copying the elements of the initializer list.
  std::complex<double> z = {0, std::numbers::pi};    // use constructor of complex to initialize z with real part 0 and imaginary part pi.
  std::vector<double> v = {1.0, 2.0, 3.0};    // v is a vector of doubles, initialized by copying the elements of the initializer list.
}

void g() {
  auto x1 = {1, 2, 3, 4};
  auto x2 = {1.0, 2.0, 3.0};
}

int main() {
  g();
}
