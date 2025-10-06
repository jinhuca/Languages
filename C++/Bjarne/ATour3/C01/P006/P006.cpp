// P006.cpp : 
import std;

// Don't do the following: declaring without initialization.
void declareVariables() {
  bool b;       // Boolean, possible values are true and false
  char c;       // character, for example, 'a', 'z', and '9'
  int i;        // integer, for example, -273, 43,..
  double d;     // double-precision floating-point number, e.g., -2343,52
  unsigned u;   // non-negative integer, use for bitwise logical operations
}

void getSize() {
  std::cout << "Size of bool is: " << sizeof(bool) << '\n';
  std::cout << "Size of char is: " << sizeof(char) << '\n';
  std::cout << "Size of int is: " << sizeof(int) << '\n';
  std::cout << "Size of double is: " << sizeof(double) << '\n';
  std::cout << "Size of unsigned is: " << sizeof(unsigned) << '\n';
  std::cout << "Size of int32_t is: " << sizeof(std::int32_t) << '\n';
}

void numbers() {
  auto p = std::numbers::pi;
  std::cout << p << '\n';
}

int main() {
  declareVariables();
  getSize();
  numbers();
}
