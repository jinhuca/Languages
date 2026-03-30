// C140401_convenience_vs_safety.cpp 
#include <iostream>

namespace X {
  int i, j, k;
}

int k;

void f() {
  int i = 0;
  using namespace X;    // make names from X available without qualification
  i++;

}

int main() {
  std::cout << "Hello World!\n";
}
