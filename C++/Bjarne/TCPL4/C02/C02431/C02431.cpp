// C02431.cpp : Exceptions
import std;

class Vector {
public:
  Vector(int s) :sz { s }, elem { new double[s] } {
    for(int i = 0; i != s; ++i) {
      elem[i] = i * 3;
    }
  }
  int size() const { return sz; }
  double& operator[](int i) {
    if(i < 0 || i >= sz) throw std::out_of_range("Accessing Vector by operator[] is out of range.");
    return elem[i];
  }
private:
  double* elem;
  int sz;
};

void f(Vector& v) {
  try {
    v[v.size()] = 9;
  }
  catch(std::out_of_range& e) {
    std::cerr << e.what() << '\n';
  }
}

int main() {
  Vector v1(9);
  f(v1);
}
