// C104_Constant_Expressions.cpp 
import std;

int x1 = 7;
constexpr int x2 = 7;

//constexpr int x3 = x1;      // error: initializer is not a constant expression
constexpr int x4 = x2;      // OK, x2 is a constant expression

void f() {
  //constexpr int y3 = x1;      // error: initializer is not a constant expression
  constexpr int y4 = x2;      // OK
  // ...
}

constexpr int isqrt_helper(int sq, int d, int a) {
  return sq <= a ? isqrt_helper(sq + d, d + 2, a) : d;
}

constexpr int isqrt(int x) {
  return isqrt_helper(1, 3, x) / 2 - 1;
}

constexpr int s1 = isqrt(9);
constexpr int s2 = isqrt(1234);

int main() {
  std::cout << s2 << '\n';
}
