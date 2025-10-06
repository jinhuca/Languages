// C1626_Explicit_Constructors.cpp 
import std;

class Date {
  int d, m, y;
public:
  explicit Date(int dd = 0, int mm = 0, int yy = 0)
    : d(0), m(0), y(0) {
  }
};

void f() {
  Date d1 { 16 };
  Date d2 = Date { 15 };
  //Date d3 = { 15 };           // error: = initialization does not do implicit conversions
  //Date d4 = 15;               // error: = initialization does not do implicit conversions
}

struct X {
  explicit X() { std::cout << "explicit with no argument.\n"; }
  explicit X(int a, int b) { std::cout << "explicit with arguments " << a << " - " << b << '\n'; }
};

void g() {
  //X x1 = {};            // error: implicit
  //X x2 = { 1, 2 };      // error: implicit

  X x3 {};              // OK: explicit
  X x4 { 1, 2 };   // OK: explicit
}

int main() {
  g();
}
