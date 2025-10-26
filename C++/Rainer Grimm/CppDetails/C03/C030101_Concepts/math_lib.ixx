export module math_lib;
import std;

// define and use concept
export template<typename T>
concept Integral = std::is_integral<T>::value;
export Integral auto gcd(Integral auto a, Integral auto b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

// use require clause with concept
export template<typename T>
requires Integral<T>
T lcm(T a, T b) {
  if(a == 0 || b == 0) return 0;
  return (a * b) / gcd(a, b);
}