// P0228.cpp

#include <iostream>

void f()
{
  int x = 1;
  if(x)     // if(x!=0)
  {
    std::cout << x << " : integer is non-zero" << std::endl;
  }
  else
  {
    std::cout << x << " : integer is zero" << std::endl;
  }

  int* y = &x;
  if(y)     // if(y!=nullptr)
  {
    std::cout << y << " : pointer to a valid object" << std::endl;
  }
  else
  {
    std::cout << y << " : pointer to an invalid object" << std::endl;
  }
}

enum E1 { a, b };
enum class E2 { a, b };

void h(E1 x, E2 y)
{
  if(x)     // OK
  {
  }
  //if(y)   // error: no conversion to bool
  {
  }
  if(y==E2::a)    // OK
  {
  }
}

int max(int a, int b)
{
  return (a < b) ? b : a;
}

void f1(int i)
{
  if(i)
    int x = i + 2;
}

int main()
{
  f();
  std::cout << max(2, 5) << std::endl;
}
