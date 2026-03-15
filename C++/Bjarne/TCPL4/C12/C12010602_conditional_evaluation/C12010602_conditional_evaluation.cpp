// C12010602_conditional_evaluation.cpp 
#include <iostream>
#include <exception>

constexpr int low = 0;
constexpr int high = 99;

constexpr int check(int i) {
  return (low <= i && i < high) ? i : throw std::out_of_range("check() failed.");
}

constexpr int f(int a, int b, int c) {
  return a + b - c;
}

int main() {
  constexpr int val0 = check(50);     // OK
  std::cout << val0 << '\n';
  // constexpr int val1 = check(f(1, 4, 21));    // error: f can't evaluate at compile-time
  // constexpr int val2 = check(200);            // throws
}
