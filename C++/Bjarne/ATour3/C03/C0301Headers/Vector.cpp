#include "Vector.h"

Vector::Vector(int s) : elem { new double[s] }, sz { s } {
  for(int i = 0; i != sz; ++i) {
    elem[i] = 0;
  }
}

double& Vector::operator[](int i) {
  return elem[i];
}

int Vector::size() const {
  return sz;
}
