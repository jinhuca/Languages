// C12161_constexpr_References.cpp 
import std;

constexpr int ftbl[] { 0, 1, 1, 2, 3, 5, 8, 13 };

constexpr int fib(int n) {
  return (n < std::size(ftbl)) ? ftbl[n] : fib(n - 2) + fib(n - 1);
}

int main() {
  std::cout << fib(10) << '\n';
}
