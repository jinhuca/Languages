// P139.cpp
#include <iostream>

void h1(int i)
{
  std::cout << "the value of i is ";
  std::cout << i;
  std::cout << std::endl;
}

void h2(int i)
{
  std::cout << "the value of i is " << i << std::endl;
}

void h3()
{
  int b = 'b';
  char c = 'c';
  char x = b;
  std::cout << 'a' << b << c << x;
}

int main()
{
  h1(10);
  h2(10);
  h3();
}
