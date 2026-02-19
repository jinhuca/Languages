// C020302_classes.cpp 
#include <iostream>

class Vector {
public:
  Vector(int s) :elem {new double[s]}, sz {s} {}     // construct a Vector
  double& operator[](int i) { return elem[i]; }      // element access: subscripting
  int size() const { return sz; }  // a "const" suffix means "can be applied to const objects"
private:
  double* elem;
  int sz;
};

void f() {
  Vector v(6);
}

double read_and_sum(int s) {
  Vector v(s);                                  // make a Vector of s elements
  for(int i = 0; i != v.size(); ++i) {
    std::cin >> v[i];                           // read into elements
  }

  double sum = 0;
  for(int i = 0; i != v.size(); ++i) {
    sum += v[i];                                // take the sume of the elements
  }
  return sum;
}

int main() {
  //f();
  std::cout << read_and_sum(5) << '\n';
}
