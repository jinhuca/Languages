import Vector;
#include <iostream>
#include <stdexcept>

Vector::Vector(int s)
  : elem{ new double[s] }, sz{ s }
{
  if (s < 0)
    throw std::length_error("Vector constructor: negative size");
}

double& Vector::operator[](int i) const
{
  return elem[i];
}

int Vector::size() const
{
  return sz;
}

void Vector::print() const
{
  for (auto i = 0; i != size(); ++i)
    std::cout << elem[i] << '\t';
  std::cout << std::endl;
}


bool operator==(const Vector& v1, const Vector& v2)
{
  if (v1.size() != v2.size())
    return false;

  for (int i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i])
      return false;

  return true;
}