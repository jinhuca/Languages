// P048.cpp : Assertions
//
#include <iostream>
#include <cassert>
import Vector;

void f(const char* p)
{
  assert(p != nullptr);   // p must not be the nullptr
  // ...
}

int main()
{
  char c = 'd';
  char* x = &c;
  f(x);
}
