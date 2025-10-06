// C03211.cpp
#include <iostream>
#include "complex.h"
#include "complex_extension.h"

void f() {
  complex a { 2.3 };
  complex b { 1 / a };
  complex c1(1.3, 5.2);
  complex c2 { 7.3, 3.3 };
  auto c3 = c1 + c2;
  auto c4 = c1 - c2;
  auto c5 = c1 * c2;
  auto c6 = c1 / c2;
  
  std::cout << "+: " << "{ " << c3.real() << ", " << c3.imag() << " }\n";
  std::cout << "-: " << "{ " << c4.real() << ", " << c4.imag() << " }\n";
  std::cout << "*: " << "{ " << c5.real() << ", " << c5.imag() << " }\n";
  std::cout << "/: " << "{ " << c6.real() << ", " << c6.imag() << " }\n";
}

int main() {
  f();
}
