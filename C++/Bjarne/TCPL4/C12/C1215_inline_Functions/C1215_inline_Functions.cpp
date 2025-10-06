// C1215_inline_Functions.cpp 
import std;

inline int fac(int n) {
  return (n < 2) ? 1 : n * fac(n - 1);
}

int main() {
  std::cout << fac(10) << '\n';
}
