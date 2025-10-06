#include <iostream>

double sqrt(double);        // the square root function takes a double and returns a double

class Vector                // what is needed to use a Vector
{
public:
  Vector(int s);
  double &operator[](int i) const;
  int size() const;
private:
  double *elem;             // elem points to an array of sz doubles
  int sz;
};

double sqrt(double d)
{
  // ... algorithm
  return std::sqrt(d);
}

Vector::Vector(int s)                     // definition of the constructor
  : elem { new double[s] }, sz { s }      // initialize members
{
}

double &Vector::operator[](int i) const   // definition of subscripting
{
  return elem[i];
}

int Vector::size() const                  // definition of size()
{
  return sz;
}

int main()
{
  Vector v(3);
  v[1] = 1.2;
  std::cout << v[1] << '\n';
}
