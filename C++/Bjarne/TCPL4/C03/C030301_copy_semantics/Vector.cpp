#include "Vector.h"

Vector Vector::operator+(const Vector b) const {
  if(sz != b.size()) throw std::exception();
  Vector res(b.size());
  for(int i = 0; i != b.size(); ++i)
    res[i] = elem[i] + b.elem[i];
  return res;
}
