// P050.cpp : Four ways to use a concept - conceptsIntegralVariation.cpp
import std;

// 1. requires clause
template<typename T>
  requires std::integral<T>
auto gcd1(T a, T b) {
  if (b == 0) return a;
  else return gcd1(b, a % b);
}

// 2. trailing requires clause
template<typename T>
auto gcd2(T a, T b) requires std::integral<T> {
  if (b == 0) return a;
  else return gcd2(b, a % b);
}

// 3. constrained template parameter
template<std::integral T>
auto gcd3(T a, T b) {
  if (b == 0) return a;
  else return gcd3(b, a % b);
}

// 4. abbreviated function template
auto gcd4(std::integral auto a, std::integral auto b) {
  if (b == 0) return a;
  else return gcd4(b, a % b);
}

int main()
{
  std::cout << "gcd1(100, 10) = " << gcd1(100, 10) << '\n';
  std::cout << "gcd2(100, 10) = " << gcd2(100, 10) << '\n';
  std::cout << "gcd3(100, 10) = " << gcd3(100, 10) << '\n';
  std::cout << "gcd4(100, 10) = " << gcd4(100, 10) << '\n';
}
