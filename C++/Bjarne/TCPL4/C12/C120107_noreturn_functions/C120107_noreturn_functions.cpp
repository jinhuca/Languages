// C120107_noreturn_functions.cpp 
#include <iostream>

[[noreturn]] void exit(int i) {
  std::cout << i << '\n';
}

int main() {
  exit(3);
}
