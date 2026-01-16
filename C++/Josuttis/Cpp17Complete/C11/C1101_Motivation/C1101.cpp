// C1101.cpp : Motivation for Fold Expression
#include <iostream>

template<typename T>
auto foldSumRec(T arg) {
  return arg;
}

template<typename T1, typename... Ts>
auto foldSumRec(T1 arg1, Ts... otherArgs) {
  return arg1 + foldSumRec(otherArgs...);
}

int main() {
  std::cout << foldSumRec(1, 2, 3, 4) << '\n';
}
