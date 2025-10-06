// P054.cpp : using a concept as return type
import std;

template<typename T>
  requires std::integral<T>
std::integral auto gcd(T a, T b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main()
{
  std::cout << "gcd(100, 25) = " << gcd(100, 25) << '\n';
}
