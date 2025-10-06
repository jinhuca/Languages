#pragma once
#include <stdexcept>

template<typename T>
class Vector
{
private:
  T *elem;
  int sz;
public:
  explicit Vector(int s);             // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; }        // destructor: release resources

  T &operator[](int i);               // for non-const Vectors
  const T &operator[](int i) const;   // for const Vectors
  int size() const { return sz; }
};

template <typename T>
Vector<T>::Vector(int s)
{
  if (s < 0)
    throw std::length_error{ "Vector constructor: negative size" };
  elem = new T[s];
  sz = s;
}

template <typename T>
const T &Vector<T>::operator[](int i) const
{
  if (i < 0 || size() <= i)
    throw std::out_of_range{ "Vector::operator[]" };
  return elem[i];
}