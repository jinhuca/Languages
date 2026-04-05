// C190202_function_call.cpp 
#include <iostream>
#include <complex>

using std::pair;
using std::complex;

struct Action {
  int operator()(int);
  pair<int, int> operator()(int, int);
  double operator()(double);
} act;

int Action::operator()(int arg) {
  return arg * arg;
}

pair<int, int> Action::operator()(int a, int b) {
  return pair<int, int>(a * a, b * b);
}

double Action::operator()(double d) {
  return d;
}

void calls() {
  int x = act(2);
  auto y = act(3, 4);
  double z = act(2.3);
}

class Add {
  complex<double> val;
public:
  Add(complex<double> c) :val{c} {}
  Add(double r, double i) :val{r, i} {}

  void operator()(complex<double>& c) const { c += val; }
};

int main() {
  
}


