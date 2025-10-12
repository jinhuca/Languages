export module gcd;
import std;

export template<typename T>
concept Integral = std::is_integral<T>::value;
export Integral auto gcd1(Integral auto a, Integral auto b) {
  if(b == 0) return a;
  else return gcd1(b, a % b);
}

export template<typename T>
requires Integral<T>
T gcd2(T a, T b) {
  if(b == 0) return a;
  else return gcd2(b, a % b);
}