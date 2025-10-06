// C0602Copy.cpp
import std;
import Vector;

void bad_copy(Vector v1) {
  Vector v2 = v1;   // copy v1's representation into v2
  v1[0] = 2;          // v2[0] is now also 2!
  v2[1] = 3;          // v1[1] is now also 3!
}

int main() {
  std::cout << "Hello World!\n";
}
