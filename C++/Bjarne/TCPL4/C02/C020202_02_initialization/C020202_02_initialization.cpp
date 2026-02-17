// C020202_02_initialization.cpp 
import std;

void initialize_variables() {
  std::cout << "initializing variables:\n";
  int x {10};         // direct list initialization
  double y = 3.14;    // copy initialization
  bool b;             // default initialization (uninitialized), can't be used until assigned a value
  //std::cout << "b: " << b << " (uninitialized, value is indeterminate)\n"; 

  std::cout << "x: " << x << '\n';
  std::cout << "y: " << y << '\n';
  
  double d1 = 2.3;    // copy initialization
  double d2 { y };    // direct list initialization
  std::complex<double> c1 { d1, d2 };     // direct list initialization of a complex number
  std::vector<int> v { 1, 2, 3, 4, 5 };   // direct list initialization of a vector

  int i1 = 7.2;       // copy initialization with narrowing conversion (double to int), allowed but may lose information
  int i2 { 7.2 };     // direct list initialization with narrowing conversion, error: cannot convert double to int without loss of information
  int i3 = { 7.2 };   // copy list initialization with narrowing conversion, error: cannot convert double to int without loss of information
}

int main() {
  initialize_variables();
}
