// C0331.cpp : copying containers
import std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) :sz { s }, elem { new double[s] } {   // constructor: acquire resources
    for(int i = 0; i != s; ++i) elem[i] = 0;         // initialize elements
    std::cout << "constructed a Vector of size " << sz << '\n';
  }

  Vector(const Vector& a) : sz { a.sz }, elem { new double[a.sz] } {                 // copy constructor
    std::cout << "copy constructor.\n";
    for(int i = 0; i != a.sz; ++i) {
      elem[i] = a.elem[i];
    }
  }

  Vector& operator=(const Vector& a) {      // copy assignment operator
    std::cout << "copy assignment.\n";
    double* p = new double[a.sz];
    for(int i = 0; i != a.sz; ++i)
      p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
  }

  ~Vector() {                                         // destructor: release resources
    delete[] elem;
    std::cout << "destructed a Vector of size " << sz << '\n';
  }
  double& operator[](int i) {
    if(i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }
  int size() const { return sz; }

  Vector operator+(Vector b) const;
};

Vector Vector::operator+(const Vector b) const {
  if(sz != b.size()) throw std::exception();
  Vector res(b.size());
  for(int i = 0; i != b.size(); ++i)
    res[i] = elem[i] + b.elem[i];
  return res;
}

void print_vector(Vector& v) {
  for(int i = 0; i != v.size(); ++i) {
    std::cout << v[i] << ' ';
  }
  std::cout << '\n';
}

void bad_copy(Vector& v1) {
  Vector v2 = v1;
  print_vector(v1);
  print_vector(v2);
  v1[0] = 2;
  v2[1] = 3;
  print_vector(v1);
  print_vector(v2);
}

void f() {
  Vector v = Vector(4);
  for(int i = 0; i != v.size(); ++i)
    v[i] = i;

  print_vector(v);
  Vector v2 = Vector(4);
  for(int i = 0; i != v2.size(); ++i)
    v2[i] = i * 2;
  print_vector(v2);

  auto c = v + v2;
  print_vector(c);
  //print_vector(v);
  //bad_copy(v);
}

void h(const Vector& x, const Vector& y, const Vector& z) {
  Vector r(6);
  r = x + y + z;
}

int main() {
  Vector x(100);
  Vector y(100);
  Vector z(100);
  h(x, y, z);
}
