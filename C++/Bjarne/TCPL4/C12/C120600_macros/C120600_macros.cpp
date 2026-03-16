// C120600_macros.cpp 
#include <iostream>

#define NAME rest of line
#define EMPTY() std::cout << "empty.\n"

void f() {
  EMPTY();
}

int main() {
  f();
}
