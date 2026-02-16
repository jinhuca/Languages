// C020202_01_built_in_types_ops.cpp 
#include <iostream>

void bool_arithmetic_ops() {
  std::cout << "operations on booleans:\n";
  bool a {true};
  bool b {false};
  std::cout << std::boolalpha; // print bool as true/false instead of 1/0
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';

  std::cout << "boolean and: " << (a && b) << '\n';
  std::cout << "boolean or: " << (a || b) << '\n';

  std::cout << "boolean plus: " << static_cast<bool>(a + b) << '\n';
  std::cout << "boolean minus: " << static_cast<bool>(a - b) << '\n';
}

void bool_comparisons() {
  std::cout << "comparisons on booleans:\n";
  bool a {true};
  bool b {false};
  std::cout << std::boolalpha; // print bool as true/false instead of 1/0
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';
  std::cout << "a == b: " << (a == b) << '\n';
  std::cout << "a != b: " << (a != b) << '\n';
}

void int_arithmetic_ops() {
  std::cout << "operations on integers:\n";
  int x {10};
  int y {3};
  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
  std::cout << "x + y: " << (x + y) << '\n';
  std::cout << "x - y: " << (x - y) << '\n';
  std::cout << "x * y: " << (x * y) << '\n';
  std::cout << "x / y: " << (x / y) << '\n'; // integer division
  std::cout << "x % y: " << (x % y) << '\n'; // modulus operator
}

void double_arithmetic_ops() {
  std::cout << "operations on doubles:\n";
  double a {1.5};
  double b {2.5};
  std::cout << "a: " << a << '\n';
  std::cout << "b: " << b << '\n';
  std::cout << "a + b: " << (a + b) << '\n';
  std::cout << "a - b: " << (a - b) << '\n';
  std::cout << "a * b: " << (a * b) << '\n';
  std::cout << "a / b: " << (a / b) << '\n'; // floating-point division
}



int main() {
  bool_arithmetic_ops();
  int_arithmetic_ops();
}
