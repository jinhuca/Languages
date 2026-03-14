// C110504_function_style_cast.cpp 
#include <complex>
using std::complex;

void f(double d) {
  int i = int(d);             // truncate d
  complex z = complex(d);     // make a complex from d
}

void f(double d, char* p) {
  int a = int(d);             // truncate d
  int b = int(p);             // not portable
}

int main() {
  double dx = 1.23;
  char c = 'c';
  char* pc = &c;
  f(dx);
  f(dx, pc);
}
