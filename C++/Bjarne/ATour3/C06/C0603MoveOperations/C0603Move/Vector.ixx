export module Vector;
import std;

export class Vector {
public:
  explicit Vector(int s) : elem { new double[s] }, sz { s } {
    for(int i = 0; i != s; ++i) {
      elem[i] = 0;
    }
    std::cout << "ordinary constructor completed.\n";
  }

  Vector(std::initializer_list<double> lst)
    : elem { new double[lst.size()] }, sz { static_cast<int>(lst.size()) } {
    std::copy(lst.begin(), lst.end(), elem);
    std::cout << "initializer_list constructor completed.\n";
  }

  Vector(const Vector& a)         // copy constructor
    : elem { new double[a.sz] }, sz { a.sz } {  // (1) allocate space
    for(int i = 0; i != sz; ++i) {              // (2) copy elements
      elem[i] = a.elem[i];
    }
    std::cout << "copy constructor called.\n";
  }

  Vector& operator=(const Vector& a) {  // copy assignment
    double* p = new double[sz];
    for(int i = 0; i != a.sz; ++i) {
      p[i] = a.elem[i];
    }
    delete[] elem;
    elem = p;
    sz = a.sz;
    std::cout << "copy assignment called.\n";
    return *this;
  }

  // move constructor
  Vector(Vector&& a)
    :elem { a.elem }, sz { a.sz } {
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move constructor called.\n";
  }

  // move assignment
  Vector& operator=(Vector&& a) {
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move assignment called.\n";
    return *this;
  }

  ~Vector() {
    delete[] elem;
    std::cout << "destructor finished.\n";
  }
  double& operator[](int i) {
    return elem[i];
  }

  int size() const {
    return sz;
  }
private:
  double* elem;
  int sz;
};