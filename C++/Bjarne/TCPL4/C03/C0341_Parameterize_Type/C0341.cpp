// C0341.cpp : template - parameterized types
import std;

template<typename T>
class Vector {
private:
  T* elem;
  int sz;
public:
  Vector(int s) : elem { new T[s] }, sz { s } { std::cout << "Vector constructed.\n"; }
  ~Vector() { delete[] elem; std::cout << "vector destructed.\n"; }
  T& operator[](int i) {
    if(i < 0 || i >= size()) throw std::out_of_range("Vector::operator[]");
    return elem[i];
  }
  const T& operator[](int i) const {
    if(i < 0 || i >= size()) throw std::out_of_range("Vector::operator[]");
    return elem[i];
  }
  int size() const { return sz; }
};

template<typename T>
T* begin(Vector<T>& x) {
  std::cout << "begin = " << x[0] << ' ';
  return x.size() ? &x[0] : nullptr;
}

template<typename T>
T* end(Vector<T>& x) {
  return begin(x) + x.size();
}

void for_range_demo(Vector<int>& v) {
  for(const auto& e : v) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

void f() {
  Vector<char> vc(200);
  throw std::exception();
  Vector<std::string> vs(20);
  Vector<std::list<int>> vli(45);
}

void first_try() {
  try {
    f();
  }
  catch(...) {
    std::cout << "calling thread ended.\n";
  }
}

void vector_init(Vector<std::string>& vs) {
  for(int i = 0; i != vs.size(); ++i) {
    vs[i] = 'H';
  }
}

void write(const Vector<std::string>& vs) {
  for(int i = 0; i != vs.size(); ++i) {
    std::cout << vs[i] << '\n';
  }
}

void second_try() {
  Vector<std::string> vs1(5);
  vector_init(vs1);
  write(vs1);
}

void try_for_range() {
  Vector<int> vi(5);
  for(int i = 0; i != vi.size(); ++i) {
    vi[i] = i;
  }
  for(const auto& i : vi)
    std::cout << i << ' ';
  std::cout << '\n';
}

int main() {
  //first_try();
  //second_try();
  try_for_range();
}
