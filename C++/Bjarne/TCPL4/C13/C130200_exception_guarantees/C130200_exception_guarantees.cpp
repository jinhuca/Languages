// C130302_exception_guarantees.cpp 
#include <iostream>

struct Bad {};

void f(int i) {
  int* p = new int[10];
  // ...
  if(i < 0) {
    delete[] p;   // delete before the throw or leak
    throw Bad();
  }
  // ...
}

int main() {
  std::cout << "Hello World!\n";
}
