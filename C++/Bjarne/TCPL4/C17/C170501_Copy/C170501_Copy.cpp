// C170501_Copy.cpp 
import std;

template<typename T>
class Matrix {
  std::array<int, 2> dim;     // two dimensions
  T* elem;                    // pointer to dim[0] * dim[1] elements of type T
public:
  Matrix(int d1, int d2) : dim { d1, d2 }, elem { new T[d1 * d2] } { }
  int size() const { return dim[0] * dim[1]; }

  Matrix(const Matrix&);              // copy constructor
  Matrix& operator=(const Matrix&);   // copy assignment

  Matrix(Matrix&&) noexcept;                   // move constructor
  Matrix& operator=(Matrix&&) noexcept;        // move assignment

  ~Matrix() { delete[] elem; }        // destructor
};

template <typename T>   // copy constructor
Matrix<T>::Matrix(const Matrix& m)
  : dim { m.dim }, elem { new T[sizeof(T) * m.size()] } {
  std::uninitialized_copy(m.elem, m.elem + m.size(), elem);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m) {  // copy assignment     
  if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
    throw std::runtime_error("Bad size in Matrix = ");
  std::copy(m.elem, m.elem + m.size(), elem);
  return *this;
}

void f() {
  Matrix<int> m1(2, 3);
  Matrix<int> m2 { m1 };
}

int main() {

}
