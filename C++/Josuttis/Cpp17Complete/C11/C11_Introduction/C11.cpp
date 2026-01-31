// C11.cpp : Introduction to Fold Expression
#include <iostream>

template<typename... T>
auto foldSum(T... args) {
  return (... + args);     // ((arg1 + arg2) + arg3) ...
}

int main() {
  int val1 = 11;
  std::cout << foldSum(1, 5, val1, 9) << '\n';

  std::cout << foldSum(std::string("Hello "), "world", "!");
}
