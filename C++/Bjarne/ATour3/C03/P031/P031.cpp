#include "Vector.h"     // get Vector's interface
#include <iostream>     // get the standard-library math function interface including sqrt()

double sqrt_sum(const Vector& v)
{
  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
  {
    sum += std::sqrt(v[i]);
  }
  return sum;
}

int main()
{
  auto v = Vector(3);
  v[0] = 3;
  v[1] = 5;
  v[2] = 9;
  std::cout << sqrt_sum(v) << '\n';
}
