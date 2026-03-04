// C0707_references.cpp 
#include <iostream>

template<typename T>
class vector {
  T* elem;     // pointer to the first element
public:
  T& operator[](int n) { return elem[n]; }    // return reference to element
  const T& operator[](int n) const { return elem[n]; }   // return reference to const element
  void push_back(const T& a) {   // pass element to be added by reference
  }
};

void f(vector<double>& v) {
  double d1 = v[1];   // copy the value of the double referred to by v.operator[](1) into d1
  v[2] = 7;           // place 7 in the double referred to by the result of v.operator[](2)
  v.push_back(d1);    // give push_back() a reference to d1 to work with
}

int main() {
  vector<double> v;
  f(v);
}
