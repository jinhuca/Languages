// C190202_function_call.cpp 
#include <iostream>
#include <complex>
#include <vector>
#include <list>
#include<algorithm>

using std::pair;
using std::complex;
using std::vector;
using std::list;

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

void call_operators() {
  int x = act(2);
  pair<int,int> y = act(3, 4);
  double z = act(2.3);
}

class Add {
  complex<double> val;
public:
  Add(complex<double> c) :val{c} {}
  Add(double r, double i) :val{r, i} {}

  void operator()(complex<double>& c) const { c += val; }
};

void h1(vector<complex<double>>& vec, list<complex<double>>& lst, complex<double> z) {
  for_each(vec.begin(), vec.end(), Add(2, 3));
  for_each(lst.begin(), lst.end(), Add(z));
}

void h2(vector<complex<double>>& vec, list<complex<double>>& lst, complex<double> z) {
  for_each(vec.begin(), vec.end(), [](complex<double>& a) {a += {2, 3}; });
  for_each(lst.begin(), lst.end(), [z](complex<double>& a) {a += z; });
}

int main() {
  
}


