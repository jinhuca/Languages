// C1216_constexpr_Functions.cpp 
import std;

constexpr int fac(int n) {
  return (n > 1) ? n * fac(n - 1) : 1;
}

constexpr int f9 = fac(9);    // must be evaluated at compile time

void f(int n) {
  int f5 = fac(5);            // may be evaluated at compile time
  int fn = fac(n);              // evaluated at run time (n is a variable)

  constexpr int f6 = fac(6);  // must be evaluated at compile time
  //constexpr int fnn = fac(n);   // error: can't guarantee compile-time evaluation (n is a variable)

  char a[fac(4)];             // OK: array bounds must be constants and fac() is constexpr
  //char a2[fac(n)];              // error: array bounds must be constants and n is a variable
}

int main() {
  std::cout << f9 << '\n';
}
