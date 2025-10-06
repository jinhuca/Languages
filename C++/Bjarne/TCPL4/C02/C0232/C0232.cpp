// C0232.cpp : Classes
import std;

class Vector {
public:
  Vector(int s) : elem { new double[s] }, sz { s } {}   // construct a Vecotr
  double& operator[](int i) { return elem[i]; }         // element access: subscribing
  int size() const { return sz; }   // a "const" suffix means "can be applied to const objects"
private:
  double* elem;     // pointer to the elements
  int sz;           // the number of elements
};

double read_and_sum(int s) {
  Vector v { s };       // make a Vector of s elements
  for(int i = 0; i != v.size(); ++i) {
    std::cin >> v[i];
  }

  double sum = 0;
  for(int i = 0; i != v.size(); ++i) {
    sum += v[i];
  }
  return sum;
}

int main() {
  std::cout << read_and_sum(5) << '\n';
}
