// C120201_reference_arguments.cpp 
#include <iostream>
#include <vector>
using std::vector;

void f(int val, int& ref) {
  ++val;
  ++ref;
}

void g() {
  int i = 1;
  int j = 1;
  f(i, j);
}

struct large {};
void h(const large& arg) {
  // the value of arg cannot be changed
}
void k(large& arg) {
  // assume that k() modifies arg
}

void strcpyx(char* to, const char* from) {
  while(*to++ = *from++);
}

float fsqrt(const float& r) {
  return std::sqrt(r);
}

void fg(double d) {
  float r = fsqrt(2.0f);    // pass reference to temp holding 2.0f
  r = fsqrt(r);             // pass reference to r
  r = fsqrt(d);             // pass reference to temp holding static_cast<float>(d)
}

void ff(vector<int>& v) {}          // (non-const) lvalue reference argument
void ff(const vector<int>& v) {}    // const lvalue reference argument
void ff(vector<int>&& v) {}         // rvalue reference argument

void ffg(vector<int>& vi, const vector<int>& cvi) {
  ff(vi);                           // call ff(vector<int>&)
  ff(cvi);                          // call ff(const vector<int>&)
  ff(vector<int>{1, 2, 3, 4});      // call ff(vector<int>&&)
}

int main() {
  g();

  const char* source = "hello";
  char dest[6];
  strcpyx(dest, source);
}
