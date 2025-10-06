// P042.cpp : too specifc
import std;

void needInt(int i) {
  std::cout << "int: " << i << '\n';
}

int main()
{
  std::cout << std::boolalpha << '\n';
  double d { 1.234 };
  std::cout << "double: " << d << '\n';
  needInt(d);

  bool b { true };
  std::cout << "bool: " << b << '\n';
  needInt(b);
}
