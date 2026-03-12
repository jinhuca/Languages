// C110103_conditional_expressions.cpp 
#include <iostream>
#include <exception>

void fct(int* p) {
  int i = (p) ? *p : throw std::runtime_error { "unexpected nullptr" };
  std::cout << "the pointed value of passed pointer is: " << i << '\n';
}

int main() {
  int* p1 = new int { 1 };
  fct(p1);
  int* p2 = nullptr;
  fct(p2);
}
