// C0501Complex.cpp: Concrete Types demonstration
#include "complexExtensions.h"
#include <iostream>

void demo1() {
  complex x0;
  complex x1(3, 2);
  complex x2 = x1;
  x2 = x0 + x1;
}

void f2() {
  complex a { 2.3 };
  complex b { 1 / a };
}

int main() {
  demo1();
  f2();
}
