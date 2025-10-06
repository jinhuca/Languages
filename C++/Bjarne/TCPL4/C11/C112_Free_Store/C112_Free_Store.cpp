// C112_Free_Store.cpp 
import std;

void f() {
  auto pc = new std::complex<double> {};    // the complex is initialized to {0,0}
  auto pi = new int {};                     // the int is initialized to 0;
}

int main() {
  f();
}
