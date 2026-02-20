#include "Vector.h"
#include <stdexcept>

Vector::Vector(int s) {
  if(s < 0) throw std::length_error("Vector constructor size.");
  elem = new double[s];
  sz = s;
}

int Vector::size() const {
  return sz;
}

double& Vector::operator[](int index) {
  if(index < 0 || size() <= index) throw std::out_of_range {"Vector::operator[]"};
  return elem[index];
}