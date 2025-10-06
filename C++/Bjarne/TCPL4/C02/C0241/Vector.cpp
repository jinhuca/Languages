#include "Vector.h"

Vector::Vector(int s) : elem { new double[s] }, sz { s } {
  for(int i = 0; i != s; ++i) {
    elem[i] = i * i;
  }
}
double& Vector::operator[](int i) { return elem[i]; }
int Vector::size() const { return sz; }


