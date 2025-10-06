// C0332.cpp : moving containers
import std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) :sz { s }, elem { new double[s] } {
    for(int i = 0; i != s; ++i) elem[i] = 0;
    std::cout << "constructed a Vector of size " << sz << '\n';
  }

  Vector(const Vector& a) : sz { a.sz }, elem { new double[a.sz] } {
    std::cout << "copy constructor.\n";
    for(int i = 0; i != a.sz; ++i) {
      elem[i] = a.elem[i];
    }
  }

  Vector& operator=(const Vector& a) {
    std::cout << "copy assignment.\n";
    double* p = new double[a.sz];
    for(int i = 0; i != a.sz; ++i)
      p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
  }

  Vector(Vector&& a) : sz { a.sz }, elem { a.elem } {
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move constructor.\n";
  }

  Vector& operator=(Vector&& a) {
    sz = a.sz;
    elem = a.elem;
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move assignment.\n";
    return *this;
  }

  ~Vector() {
    delete[] elem;
    std::cout << "destructed a Vector of size " << sz << '\n';
  }

  double& operator[](int i) const {
    if(i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }

  double& operator[](int i) {
    if(i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }

  int size() const { return sz; }
};

Vector operator+(const Vector& a, const Vector& b) {
  Vector res(a.size());
  for(int i = 0; i != a.size(); ++i)
    res[i] = a[i] + b[i];
  return res;
}

Vector f(const Vector& x, const Vector& y, const Vector& z) {
  return x + y + z;
}

Vector f() {
  Vector x(1000);
  Vector y(1000);
  Vector z(1000);
  z = x;
  y = std::move(x);
  return z;
}

void g() {
  Vector a(5);
  Vector b(5);
  Vector c(5);
  Vector d = f(a, b, c);
}

void moveConstructor()
{
  Vector v1(5);
  Vector v2 = std::move(v1);
}
int main() {
  //f();
  moveConstructor();
}
