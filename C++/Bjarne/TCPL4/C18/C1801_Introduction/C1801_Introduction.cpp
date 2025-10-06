// C1801_Introduction.cpp 
import std;
import complex;

void f() {
  complex a = complex { 1.2, 3 };
  complex b { 1.2,2 };
  complex c { b };

  a = b + c;
  b = b + c * a;
  c = a * b + complex(1, 2);
}

int main() {
  f();
}
