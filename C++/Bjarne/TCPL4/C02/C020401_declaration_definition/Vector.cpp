#include "Vector.h"
import std;

double sqrt2(double d) {
  return std::sqrt(d);
}

Vector::Vector(int s) : elem{new double[s]}, sz{s} {
}

double& Vector::operator[](int index) {
  return elem[index];
}

int Vector::size() const {
  return sz;
}
