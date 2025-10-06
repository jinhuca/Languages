// P022.cpp : consteval and constinit
import std;

// an immediate function
consteval int sqr(int n) {
  return n * n;
}

int main()
{
  constexpr int r = sqr(100);
  std::cout << "call immediate function - " << r << '\n';
  int x = 100;
  //int r2 = sqr(x);      // 'sqr': call to immediate function is not a constant expression
}
