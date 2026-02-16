// C020202_02_initialization.cpp 
#include <iostream>

void initialize_variables() {
  std::cout << "initializing variables:\n";
  int x {10}; // direct list initialization
  double y = 3.14; // copy initialization
  bool b; // default initialization (uninitialized)
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
  std::cout << "b: " << b << " (uninitialized, value is indeterminate)\n"; }

int main() {
  initialize_variables();
}
