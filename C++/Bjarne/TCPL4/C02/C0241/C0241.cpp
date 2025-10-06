// C0241.cpp : separate compilation
#include <iostream>
#include "Vector.h"

int main()
{
  Vector v1(4);
  std::cout << "size of v1 = " << v1.size() << '\n';
  std::cout << "value of v1[3] = " << v1[3] << '\n';
}
