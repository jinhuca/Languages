import std;
import Vector;

namespace P057
{
  Vector::Vector(int s) : elem { new double[s] }, sz { s }
  {
    for(int i = 0; i != s; ++i)
    {
      elem[i] = 0;
    }
  }

  Vector::Vector(std::initializer_list<double> lst)
    :elem { new double[lst.size()] }, sz { static_cast<int>(lst.size()) }
  {
    std::ranges::copy(lst, elem);
  }

  Vector::~Vector()
  {
    delete[] elem;
  }

  double &Vector::operator[](int i) const
  {
    if(!(0 < i && i < size()))
    {
      throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
  }

  int Vector::size() const
  {
    return sz;
  }

  void Vector::push_back(double)
  {
  }
}