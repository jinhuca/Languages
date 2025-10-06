// P0528.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
import complex;

void f()
{
  complex a = complex{ 1,3.1 };
  complex b{ 1.2,3 };
  complex c{ b };

  a = b + c;
  b = b + c * a;
  c = a * b + complex(1, 2);
}

int main()
{
  std::cout << "Hello World!\n";
}
