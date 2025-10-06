export module Vector;
import std;

export template<typename T>
class Vector {
public:
  explicit Vector(int s);                 // constructor: establish invariant, acquire resources
  ~Vector() { delete[] elem; }            // destructor: release resources

  Vector(const Vector& a);                // copy constructor
  Vector& operator=(Vector& a);           // copy assignment

  Vector(Vector&& a) noexcept;            // move constructor
  Vector& operator=(Vector&& a) noexcept; // move assignment

  T& operator[](int i);                   // for non-const Vectors
  const T& operator[](int i) const;       // for const Vectors
  int size() const { return sz; }
private:
  T* elem;                                // elem points to an array of sz elements of type T
  int sz;                                 // size of array elem
};

template <typename T>
Vector<T>::Vector(int s) {
  if(s < 0) {
    throw std::length_error { "Vector constructor: negative size" };
  }
  elem = new T[s];
  sz = s;
  std::cout << "explicit constructor called.\n";
}

template <typename T>
Vector<T>::Vector(const Vector& a)
  : elem { new T[a.sz] }, sz { a.sz } {
  for(int i = 0; i != sz; ++i) {
    elem[i] = a.elem[i];
  }
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector& a) {
  T* p = new T[a.sz];
  for(int i = 0; i != a.sz; ++i) {
    p[i] = a.elem[i];
  }
  delete[] elem;
  elem = p;
  sz = a.sz;
  return *this;
}

template <typename T>
Vector<T>::Vector(Vector&& a) noexcept : elem { a.elem }, sz { a.sz } {
  a.elem = nullptr;
  a.sz = 0;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& a) noexcept : elem { a.elem }, sz { a.sz } {
  a.elem = nullptr;
  a.sz = 0;
  return *this;
}


template <typename T>
T& Vector<T>::operator[](int i) {
  if(i < 0 || i >= size()) {
    throw std::out_of_range { "Vector::operator[] access out of range." };
  }
  return elem[i];
}

template <typename T>
const T& Vector<T>::operator[](int i) const {
  if(i < 0 || size() <= i) {
    throw std::out_of_range { "Vector::operator[] access out of range." };
  }
  return elem[i];
}

export template<typename T>
T* begin(Vector<T>& x) {
  return &x[0];             // pointer to first element or to one-past-the-last element
}

export template<typename T>
T* end(Vector<T>& x) {
  return &x[0] + x.size();  // pointer to one-past-the-last element
}