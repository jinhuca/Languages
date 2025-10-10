// C030101_Concepts.cpp 
import std;

template<typename T>
concept Integral = std::is_integral<T>::value;
Integral auto gcd(Integral auto a, Integral auto b) {
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int main() {
  std::cout << gcd(48, 18) << std::endl;
  std::cout << gcd(48u, 8u) << std::endl;
}
