#include "Vector.h"
#include <cmath>

double sqrt2(double t) {
  return std::sqrt(t);
}

Vector::Vector(int s) 
  :sz {s}, elem {new double[s]} {
}

int Vector::size() const {
  return sz;
}

double& Vector::operator[](int index) {
  return elem[index];
}