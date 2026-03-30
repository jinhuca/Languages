// C140205_namespaces_are_opn.cpp
#include <iostream>
#include "my_header.h"

namespace A {
  int f() { return 1; }   // now A has member f()
}

namespace A {
  int g() { return 2; }   // now A has two members: f() and g()
}

int main() {
  std::cout << "Hello World!\n";
}
