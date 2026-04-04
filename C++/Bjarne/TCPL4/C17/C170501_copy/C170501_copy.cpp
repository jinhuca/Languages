// C170501_copy.cpp 
#include <iostream>
#include <array>
#include <memory>
#include <exception>

using std::array;

template<typename T>
class Matrix {
  array<int, 2> dim;    // two dimensions
  T* elem;              // pointer to dim[0]*dim[1] elements of type T
public:
  Matrix(int d1, int d2) :dim{d1, d2}, elem{new T[d1 * d2]} {}
  int size() const { return dim[0] * dim[1]; }

  Matrix(const Matrix&);                // copy constructor
  Matrix& operator=(const Matrix&);     // copy assignment

  Matrix(Matrix&&);                     // move constructor
  Matrix& operator=(Matrix&&);          // move assignment

  ~Matrix() { delete[] elem; }
  // ...
};

template<typename T>
Matrix<T>::Matrix(const Matrix& m)                            // copy constructor
  : dim{m, dim}
  , elem{static_cast<T*>(new char[sizeof(T) * m.size()])}     // get uninitialized space
{
  uninitialized_copy(m.elem, m.elem + m.size(), elem);        // initialize elements in elem[0:elem(0:m.size())
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)              // copy assignment
{
  if(dim[0] != m.dim[0] || dim[1] != m.dim[1])
    throw std::runtime_error("bad size in Matrix = ");
  copy(m.elem, m.elem + m.size(), elem);                      // copy elements
  return *this;
}

int main() {
  std::cout << "Hello World!\n";
}
