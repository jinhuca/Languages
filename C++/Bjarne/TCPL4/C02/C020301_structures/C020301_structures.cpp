// C020301_structures.cpp 
#include <iostream>

struct Vector {        // define type
  int sz;              // number of elements
  double* elem;        // pointer to elements
};

Vector v;              // declare a variable of type Vector

void vector_init(Vector& v, int s) {   // initialize a variable of type Vector
  v.elem = new double[s];   // allocate an array of s doubles
  v.sz = s;                 // set the size
}

// read s integers from cin and return their sum; s is assumed to be positive
double read_and_sum(int s) {
  Vector v;
  vector_init(v, s);   // initialize v to hold s doubles
  for(int i = 0; i != s; ++i) {
    std::cin >> v.elem[i];   // read each element from input
  }

  double sum = 0;
  for(int i = 0; i != s; ++i) {
    sum += v.elem[i];   // add each element to the sum
  }
  return sum;   // return the total sum
}

void f(Vector v, Vector& rv, Vector* pv) {
  // v is a copy of the argument passed to f; changes to v do not affect the caller
  // rv is a reference to the argument passed to f; changes to rv affect the caller
  // pv is a pointer to the argument passed to f; changes to *pv affect the caller
  int i1 = v.sz;     // access size through copy
  int i2 = rv.sz;    // access size through reference
  int i3 = pv->sz;   // access size through pointer
}

int main() {
  vector_init(v, 5);   // initialize v to hold 5 doubles
  std::cout << v.elem[0] << '\n';  // uninitialized, value is indeterminate / undefined behavior

  std::cout << "Enter 3 integers: ";
  std::cout << read_and_sum(3) << '\n';  // read 3 doubles from input and print their sum
}
