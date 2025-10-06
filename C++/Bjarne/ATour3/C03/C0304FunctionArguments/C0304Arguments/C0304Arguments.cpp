// C0304Arguments.cpp 
import std;

int sum(const std::vector<int>& v) {
  int s = 0;
  for(const int i : v) {
    s += i;
  }
  return s;
}

int& bad() {
  int x;
  x = 12;
  return x;
}

auto mul(int i, double d) { return i * d; }

auto mul2(int i, double d) -> double { return i * d; }

int main() {
  std::vector<int> fib = { 1,2,3,5,8,13,21 };
  std::cout << sum(fib) << '\n';
  std::cout << bad() << '\n';

  std::cout << mul(2, 2.3) << '\n';
}
