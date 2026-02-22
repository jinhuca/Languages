// C030203_virtual_functions.cpp 
#include "Vector_container.h"
#include "List_container.h"
#include <iostream>
void use(Container& c) {
  const int sz = c.size();
  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << '\n';
  }
}
void g() {
  Vector_container vc(10);
  use(vc);
}

void h() {
  List_container lc = { 1,2,3 };
  use(lc);
}

int main() {
  g();
  h();
}
