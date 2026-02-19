// C020401_declaration_definition.cpp 
#include "Vector.h"
#include <iostream>

void f() {
  Vector v(3);
  std::cout << "size of v = " << v.size() << '\n';
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
  std::cout << v[1] << '\n';

  std::cout << sqrt2(1.6) << '\n';
}

int main() {
  f();
}
