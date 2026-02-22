#pragma once
import std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) :sz {s}, elem {new double[s]} {   // constructor: acquire resources
    for(int i = 0; i != s; ++i) elem[i] = 0;         // initialize elements
    std::cout << "constructed a Vector of size " << sz << '\n';
  }

  Vector(const Vector& a) : sz {a.sz}, elem {new double[a.sz]} {  // copy constructor
    std::cout << "copy constructor.\n";
    for(int i = 0; i != a.sz; ++i) {    // copy each element
      elem[i] = a.elem[i];
    }
  }

  Vector& operator=(const Vector& a) {  // copy assignment operator
    std::cout << "copy assignment.\n";
    double* p = new double[a.sz];
    for(int i = 0; i != a.sz; ++i)
      p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
  }

  ~Vector() {                           // destructor: release resources
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