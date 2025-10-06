// P004.cpp :
import std;

struct Elem {};

// type: double(const vector<double>&, int) 
double get(const std::vector<double>& vec, int index);

// type: char& String::(int)
char& String::operator[](int index);


double sqrt(double d);    // return the square root of d
double square(double);    // return the square of the argument

// Declaration - 
Elem* next_elem();      // no argument; return a pointer to Elem (an Elem*)
void exit(int);         // int argument; return nothing
double sqrt2(double);   // double argument; return a double

void f() {
  double s2 = sqrt2(2);         // call sqrt() with the argument double(2)
  double s3 = sqrt2("three");  // error: sqrt() requires an argument of type double
}

int main() {
  f();
}

double sqrt2(double x) {
  return std::sqrt(x);
}