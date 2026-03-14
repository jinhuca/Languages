// C110501_construction_conversions.cpp 
#include <iostream>
#include <string>
#include <complex>

using std::complex;

void h() {
  auto d1 = double{2};      // d1 = 2.0
  double d2{double{2}/4};   // d2 = 0.5
  //int i1 = int{1.2};      // no conversion from floating-point to int
  std::string s1{"hello"};
}

void f(int i) {
  std::cout<<"call f(int i) with i = "<<i<<'\n';
}

void f(double d) {
  std::cout<<"call f(double d) with d = "<<d<<'\n';
}

void g(int i, double d) {
  f(i);                             // call f(int)
  // f(double{i});                  // error: {} doesn't do int to floating conversion
  
  f(d);                             // call f(double)
  // f(int{d});                     // error: {} doesn't truncate
  f(static_cast<int>(d));           // call f(int) with a truncated value

  f(round(d));                      // call f(double) with a rounded value
  f(static_cast<int>(lround(d)));   // call f(int) with rounded value
                                    // if the rounded overflows the int, this still trucates
}

void k() {
  static_assert(sizeof(int)!=sizeof(double), "unexpected size");
  constexpr int x = std::numeric_limits<int>::max();    // largest possible integer
  double d = x;
  int y = d;
  double e{1234};                             // fine
}

void d(char* p) {
  // int x = int{p};                    // error: no char* to int conversion
  using Pint = int*;
  // int* p2 = Pint{p};                 // error: no char* to int* conversion
}

template<typename T>
void fx(const T& t) {
  std::cout<<t<<'\n';
}

void u() {
  fx(int{});                            // default int value
  fx(complex<double>{});                // default complex value
}

int main() {
  h();
  g(1, 21.2);
  k();
  char c = 'c';
  char* p = &c;
  d(p);
  u();
}
