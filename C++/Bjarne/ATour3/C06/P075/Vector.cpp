import Vector;
#include <algorithm>

Vector::Vector(const Vector &a)               // copy constructor
  :elem { new double[a.sz] }, sz { a.sz }     // allocate space for elements
{
  for(int i = 0; i != sz; ++i)
    elem[i] = a.elem[i];
}

Vector &Vector::operator=(const Vector &a)    // copy assignment
{
  const auto p = new double[a.sz];
  for(int i = 0; i != a.sz; ++i)
    p[i] = a.elem[i];
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this;
}

Vector::Vector(Vector &&a) noexcept           // move constructor
  :elem { a.elem }, sz { a.sz }               // grab the elements from a
{
  a.elem = nullptr;
  a.sz = 0;
}

Vector &Vector::operator=(Vector &&a) noexcept
{
  elem = std::move(a.elem);
  sz = a.sz;
  return *this;
}

double& Vector::operator[](int i)
{
  return elem[i];
}

const double& Vector::operator[](int i) const
{
  return elem[i];
}
