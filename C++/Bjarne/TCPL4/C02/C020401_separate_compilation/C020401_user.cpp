// C020401_user.cpp 
#include "Vector.h"
#include <iostream>

double sqrt_sum(Vector& v) {
  double sum = 0;
  for(int i = 0; i != v.size(); ++i) {
    sum += sqrt2(v[i]);
  }
  return sum;
}

int main() {
  Vector v(5);
  for(int i = 0; i != v.size(); ++i) {
    v[i] = i * 1.3;
  }
  std::cout << sqrt_sum(v) << '\n';
}
