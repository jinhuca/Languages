// C180300_complex_number_type.cpp 
#include <iostream>
#include "complex.h"
using namespace C18;
//using C18::complex;

void f(complex x, complex y) {
  auto r1 = x + y;
  auto r2 = x + 2;
  auto r3 = 2 + x;
  auto r4 = 2 + 3;
}

void convert_double_to_complex() {
  complex c1{3};
  complex c2 = 4;
}

void default_copy() {
  complex z;
  complex x{1, 2};
  complex y{x};     // default copy constructor
  z = x;            // default copy assignment
}

void complex_literals() {
  //using namespace C18;
  auto x{2.3_i};
  complex z1{12 + 23.1_i};

}

int main() {
  complex_literals();
}
