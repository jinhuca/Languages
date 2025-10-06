// C0603Move.cpp
import std;
import Vector;

Vector f() {
  /*Vector x(1000);
  Vector y(2000);*/
  Vector z(3000);
  //z = x;
  //y = std::move(x);
  //...
  return z;
}

int main() {
  Vector a = f();
}
