// P091.cpp

#include <iostream>

void argumentDeduce()
{
  std::pair<int, double> p = { 1, 5.2 };
  std::pair p1 = { 1, 5.2 };
  std::cout << p.first << " , " << p.second << std::endl;
}

template<typename T>
class Vector
{
public:
  Vector(int);
  Vector(std::initializer_list<T> s)    // initializer list constructor
  {

  }
};

void f()
{
  Vector<int> v1 { 1, 2, 3 };
  Vector v2 = v1;
  auto p = new Vector { 1, 2, 3 };
}

int main()
{
  argumentDeduce();
}
