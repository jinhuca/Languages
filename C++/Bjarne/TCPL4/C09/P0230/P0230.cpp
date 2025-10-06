// P0230.cpp
#include <iostream>

void f(int val)
{
  switch(val)     // beware
  {
  case 1:
    std::cout << "case 1" << std::endl;
  case 2:
    std::cout << "case 2" << std::endl;
  default:
    std::cout << "default: case not found\n" << std::endl;
  }
}

int main()
{
  f(1);
}
