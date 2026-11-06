// C0203_classes.cpp 
import std;

class Vector {
public:
  Vector() : elem{nullptr}, sz{0} {}
  Vector(int s) : elem{new double[s]}, sz{s} {}     // construct a Vector
  double& operator[](int i) { return elem[i]; }     // element access: subscripting
  int size() { return sz; }                         // the current size}
private:
  double* elem;   // pointer to elements
  int sz;         // number of elements
};

double read_and_sum(int s) {
  Vector v(s);                                      // allocate s elements for v
  for(int i = 0; i != s; ++i)                       // read into elements
    std::cin >> v[i];

  double sum = 0;
  for(int i = 0; i != s; ++i)
    sum += v[i];                                    // compute the sum of the elements
  return sum;
}

int main() {
  //std::cout << read_and_sum(3) << std::endl;
  auto v = Vector();
  return 0;
}
