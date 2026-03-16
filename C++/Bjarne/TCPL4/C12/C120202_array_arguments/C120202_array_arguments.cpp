// C120202_array_arguments.cpp 
#include <iostream>

int strlen_x(const char*) {
  return 1;
}

void f() {
  char v[] = "Annemarie";
  int i = strlen_x(v);
  int j = strlen_x("Nicolas");
}

void f(int(&r)[4]) {
}

void g() {
  int a1[] = {1, 2, 3, 4};
  int a2[] = {1, 2};
  f(a1);        // OK
  // f(a2);     // error: wrong number of elements
}

int main() {
  f();
}
