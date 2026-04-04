// C170502_move.cpp 
#include <iostream>
#include <array>

namespace matrix_move {
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
  Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
    if(a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1])
      throw std::runtime_error("unequal Matrix sizes in +");
    Matrix res{a.dim[0], a.dim[1]};
    const auto n = a.size();
    for(int i = 0; i != n; ++n)
      res.elem[i] = a.elem[i] + b.elem[i];
    return res;
  }

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

  template<typename T>
  Matrix<T>::Matrix(Matrix&& a)                                 // move constructor
    : dim{a.dim}, elem{a.elem}                                  // grab a's representation
  {
    a.dim = {0, 0};                                             // clear a's representation
    a.elem = nullptr;
  }

  template<typename T>
  Matrix<T>& Matrix<T>::operator=(Matrix&& a)                   // move assignment
  { 
    swap(dim, a.dim);                                           // swap representation
    swap(elem, a.elem);
    return *this;
  }
}

int main()
{
}
