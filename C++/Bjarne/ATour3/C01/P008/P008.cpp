// P008.cpp 
import std;

void initialize() {
  double d1 = 2.3;                            // initialize d1 to 2.3
  double d2 { 2.3 };                          // initialize d2 to 2.3
  double d3 = { 2.3 };                        // initialize d3 to 2.3 (the = is optional with {...})
  std::complex<double> z = 1;                 // a complex number with double-precision floating-point scalars
  std::complex z2 { d1, d2 };                 // a complex number with double-precision floating-point scalars
  std::complex<double> z3 = { d1, d2 };       // the = is optional with {...}
  std::vector v { 1, 2, 3, 4, 5, 6 };         // a vector of integers

  int i1 = 7.8;                               // i1 becomes 7 (surprise?)
  int i2{ 7.8 };                            // error: floating-point to integer conversion
}

void autoVariables() {
  auto b = true;                  // a bool
  auto ch = 'x';                  // a char
  auto i = 123;                   // an int
  auto d = 1.2;                   // a double
  auto z = std::sqrt(d);          // z has the type of whatever sqrt(d) returns
  auto bb { true };               // bb is a bool
  std::cout << z << std::endl;
}

int main() {
  autoVariables();
}
