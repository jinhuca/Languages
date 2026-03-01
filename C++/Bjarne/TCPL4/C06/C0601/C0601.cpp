// C0601.cpp 
#include <iostream>

void demo_implementation_defined() {
  unsigned char c1 = 64;
  std::cout << "c1: " << c1 << std::endl; // Output: c1:
  std::cout << "Value of c1: " << static_cast<int>(c1) << std::endl; // Output: Value of c1: 64

  unsigned char c2 = 1256; // implementation-defined behavior: value exceeds the range of unsigned char
  std::cout << "c2: " << c2 << std::endl; // Output: c2: (implementation-defined value)
  std::cout << "Value of c2: " << static_cast<int>(c2) << std::endl; // Output: Value of c2: (implementation-defined value)
}

void demo_static_assertion() {
  static_assert(sizeof(int) == 4, "This code requires int to be 4 bytes");
}

const int size = 4 * 1024;
char page[size];
void f() {
  page[size + size] = 7; // implementation-defined behavior: out-of-bounds access
}

int main() {
  demo_implementation_defined();
  demo_static_assertion();
  f();
}
