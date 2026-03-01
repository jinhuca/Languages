// C0602.cpp 
#include <iostream>

float x;
int y = 7;
float f(int i) {
  return x + i; // implementation-defined behavior: using uninitialized variable x
}

void declare_variables() {
  x = y + f(2);
  std::cout << "Value of x: " << x << '\n';
}

int main() {
  declare_variables();
}
