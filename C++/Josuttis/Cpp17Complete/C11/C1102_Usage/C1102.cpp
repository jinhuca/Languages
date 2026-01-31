// C1102.cpp : Using Fold Expression
#include <iostream>

template<typename... T>
auto foldSumLeft(T... args) {
  return (... + args);    // ((arg1 + arg2) + arg3)...
}

template<typename... T>
auto foldSumRight(T... args) {
  return (args + ...);    // (arg1 + (arg2 + arg3))...
}

int main() {
  std::cout << foldSumLeft(1, 2, 3) << '\n';     // ((1 + 2) + 3)
  std::cout << foldSumLeft(std::string("Hello "), "World", "!");     // (("Hello " + "World") + "!")
  std::cout << foldSumRight("Hello ", "World", std::string("!"));
}
