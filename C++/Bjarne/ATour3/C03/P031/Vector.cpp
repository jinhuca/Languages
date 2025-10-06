#include "Vector.h"                         // get Vector's interface

Vector::Vector(int s)                       // definition of the constructor
  : elem { new double[s] }, sz { s }        // initialize members
{
}

double& Vector::operator[](int i) const     // definition of subscripting
{
  return elem[i];
}

int Vector::size() const                    // definition of size()
{
  return sz;
}