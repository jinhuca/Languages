// C030202_abstract_type.cpp 
#include <iostream>
//#include "Container.h"
#include "Vector_container.h"

void use_abstract_type_via_reference(Container& c) {
  const int sz = c.size();
  for (int i = 0; i != sz; ++i) {
    std::cout << c[i] << '\n';
  }
}

void use_abstract_type_via_pointer(Container* c) {
  const int sz = c->size();
  for (int i = 0; i != sz; ++i) {
    std::cout << c->operator[](i) << '\n';
  }
}

int main() {
  Vector_container vc(3);
  use_abstract_type_via_reference(vc);
}
