// C02432.cpp : invariants
import std;

class Vector {
public:
  Vector(int s) : sz { s }, elem { new double[s] } {
    if(s < 0) throw std::length_error { "Vector constructor Size Error." };
  }
private:
  double* elem;
  int sz;
};

void test() {
  try {
    Vector(-9);
  }
  catch(std::length_error& e) {
    std::cout << e.what() << '\n';
  }
  catch(std::bad_alloc& e) {
    std::cout << e.what() << '\n';
  }
}
int main() {
  test();
}

