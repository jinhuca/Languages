// C120300_overloaded_functions.cpp 
#include <iostream>

void print(int i) {
  std::cout << "print integer - " << i << '\n';
}

void print(const char* s) {
  std::cout << "print string - " << s << '\n';
}

int main() {
  print(123);
  print("hello");
}
