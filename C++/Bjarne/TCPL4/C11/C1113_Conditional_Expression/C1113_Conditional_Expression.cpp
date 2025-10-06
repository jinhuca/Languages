// C1113_Conditional_Expression.cpp
import std;

int max1(int a, int b) {
  int max { 0 };
  if (a < b) max = b;
  else max = a;
  return max;
}

int max2(int a, int b) {
  return a < b ? b : a;
}

void f(int* p) {
  int i = p ? *p : throw std::runtime_error { "unexpected nullptr" };
  std::cout << "i = " << i << '\n';
}

int main() {
  int a = 56;
  int b = 33;
  std::cout << max1(a, b) << '\n';
  std::cout << max2(a, b) << '\n';

  int* p = nullptr;
  int* px = &b;
  try {
    f(px);
  }
  catch (...) {
    std::cerr << "Oops.\n";
  }
}
