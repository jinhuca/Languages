#include <cmath>

import std;
import Vector;

double sqrt_sum(Vector& v)
{
  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
    sum += sqrt(v[i]);
  return sum;
};

int main()
{
  Vector v1(4);
  Vector v2(4);
  std::cout << (v1 == v2) << std::endl;
  std::cout << sqrt_sum(v1) << std::endl;
}
