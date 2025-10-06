// C0502Vector.cpp 
import std;
import Vector;

void demo_object_life_cycle() {
  Vector v1(5);
  throw std::exception("test exception");
}

void demo2() {
  Vector* gp = new Vector(100);
}

void fct(int n) {
  Vector v(n);
  {
    Vector v2(2 * n);
  }
}

int main() {
  Vector v1 { 1,2,3,4 };
  std::cout << v1[2];
}
