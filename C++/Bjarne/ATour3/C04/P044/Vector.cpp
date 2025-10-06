import Vector;
import std;

Vector::Vector(int s) : elem{ new double[s] }, sz{ s }
{
}

Vector::~Vector()
{
  
}

double& Vector::operator[](int i) const
{
  if (!(0 <= i && i < Vector::size()))
  {
    throw std::out_of_range("Vector::operator[]");
  }
  return elem[i];
}

int Vector::size() const
{
  return sz;
}
