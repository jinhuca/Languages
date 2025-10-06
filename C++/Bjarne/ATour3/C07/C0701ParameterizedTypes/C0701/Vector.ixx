export module Vector;
import std;

export template<typename T>
class Vector {
private:
  T* elem;
  int sz;
public:
  explicit Vector(int s) {
    if(s < 0)
      throw std::length_error("Vector constructor: negative size");
    elem = new T[s];
    sz = s;
  }
  ~Vector() { delete[] elem; }

  T& operator[](int i) {
    if(i < 0 || size() <= i)
      throw std::out_of_range("Vector::operator[]");
    return elem[i];
  }

  const T& operator[](int i) const {
    if(i < 0 || size() <= i)
      throw std::out_of_range("Vector::operator[]");
    return elem[i];
  }
  int size() const { return sz; }

  template<typename T>
  T* begin(Vector<T>& x) {
    return &x[0];
  }

  template<typename>
  T* end(Vector<T>& x) {
    return &x[0] + x.size();
  }
};