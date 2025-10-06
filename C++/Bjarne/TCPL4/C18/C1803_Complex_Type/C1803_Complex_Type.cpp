// C1803_Complex_Type.cpp 
import std;
import complex;

void h() {
  complex a { 1, 2 };
  complex b (1.3);
}

void f(complex x, complex y, complex z) {
  complex r1 { x + y + z };
  complex r2 { x };
  r2 += y;
  r2 += z;
  r2 += 12.3;
}

void g() {
  complex z1 { 1.2 + 12e3_i };
}

int main() {
  h();
  f(complex(), complex(1.2, 3.2), complex(4.3, 5.1));
  g();
}
