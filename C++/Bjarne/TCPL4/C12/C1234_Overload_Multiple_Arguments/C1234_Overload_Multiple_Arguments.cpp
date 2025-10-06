// C1234_Overload_Multiple_Arguments.cpp 
import std;
using Complex = std::complex;

int pow(int a, int b) { return std::pow(a, b); }
double pow(double a, double b) { return std::pow(a, b); }
Complex pow(double d, Complex c) { return std::pow(d, d); }
Complex pow(Complex c, int i) { return std::pow(i, i); }
Complex pow(Complex c1, Complex c2) { return std::pow(1, 1); }

int main() {
  std::cout << "Hello World!\n";
}
