// C0202ClassVector.cpp : 
import std;

class Vector {
public:
  Vector(int s) : elem { new double[s] }, sz { s } {}
  double& operator[](int i) { return elem[i]; }
  int size() { return sz; }
private:
  double* elem;
  int sz;
};

int main() {
  Vector v(5);
  std::cout << v[1] << '\n';
}

