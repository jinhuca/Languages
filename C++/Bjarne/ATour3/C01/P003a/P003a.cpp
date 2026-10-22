// P003a.cpp : start from main()
import std;                         // import the standard library module
using namespace std;                // use the standard library namespace

double square(double x) {           // square a double-precision floating-point number
  return x * x;
}

void print_square(double x) {       // print the square of a double-precision floating-point number
  cout << "the square of " << x << " is " << square(x) << "\n";
}

int main() {
  print_square(1.234);              // call print_square() with the argument 1.234
}
