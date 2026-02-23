// C030401_parameterized_types.cpp
#include <iostream>
#include <stdexcept>
#include <list>

template<typename T>
class Vector {
private:
  T* elem;
  int sz;
public:
  Vector(int s) {
    elem = new T[s];
    sz = s;
    std::cout << "Vector constructed.\n";
  }

  ~Vector() {
    delete[] elem;
    std::cout << "Vector destructed.\n";
  }
  
  T& operator[](int i) {
    if (i < 0 || i >= size()) throw std::out_of_range("Vector::operator[]");
    return elem[i];
  }
  
  const T& operator[](int i) const {
    if (i < 0 || i >= size()) throw std::out_of_range("Vector::operator[] const");
    return elem[i];
  }

  int size() const { return sz; }
};

void create_vectors() {
  Vector<char> vc(2000);
  Vector<std::string> vs(27);
  Vector<std::list<int>> vli(45);
}

void write(const Vector<std::string>& vs) {
  for (int i = 0; i != vs.size(); ++i) {
    std::cout << vs[i] << '\n';
  }
}

void iterate_vector() {
  Vector<std::string> vs(5);
  vs[0] = "hello";
  vs[1] = "world";
  vs[2] = "!";
  write(vs);
}

template<typename T>
T* begin(Vector<T>& x) {
  return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x) {
  return begin(x) + x.size();
}

void for_range_iterate() {
  Vector<std::string> vs(5);
  vs[0] = "hello";
  vs[1] = "world";
  vs[2] = "!";
  for (auto& s : vs)
    std::cout << s << ' ';
  std::cout << '\n';
}

int main() {
  //create_vectors();
  //iterate_vector();
  for_range_iterate();
}
