// P011Concept.cpp
import std;

// 1. define theIntegral concept
template<typename T>
concept theIntegral = std::is_integral<T>::value;

// 2a. use theIntegral concept on parameter types
theIntegral auto gcd1(theIntegral auto a, theIntegral auto b) {
  if (b == 0) return a;
  else return gcd1(b, a % b);
}

// 2b. use theIntegral with requires clause
template<typename T>
requires theIntegral<T>
T gcd2(T a, T b) {
  if (b == 0) return a;
  else return gcd2(b, a % b);
}

int main()
{
  std::cout << "gcd1(20, 14) = " << gcd1(20, 14) << '\n';
  std::cout << "gcd2(20, 12) = " << gcd2(20, 12) << '\n';
}
