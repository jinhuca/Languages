// C110501_construction_conversions.cpp 
#include <iostream>

void f() {
  auto d1 = double {2};      // d1 = 2.0
  double d2 {double{2}/4};   // d2 = 0.5
}

int main() {
  f();
}
