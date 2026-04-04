// C170202_destructors_and_resources.cpp 
#include <iostream>
using std::cout;
using std::cin;

class Vector {
public:
  Vector(int s) :elem{new double[s]}, sz{s} {   // constructor: acquire memory
    cout << "ctor.\n"; 
  }     
  ~Vector() {                                   // destructor: release memory
    cout << "dtor.\n";
    delete[] elem;
  }                    
// ...
private:
  double* elem;   // elem points to an array of sz doubles
  int sz;         // sz is non-negative
};

Vector* f(int s) {
  Vector v1(s);                 // v1 is a local variable in f
  // ...
  return new Vector(s + s);     // return a pointer to a new Vector
}

void g(int ss) {
  Vector* p = f(ss);            // p points to a Vector created by f
  // ...
  delete p;                     // free the memory allocated by f
}

int main() {
  //auto t1 = f(3);
  g(1);
}
