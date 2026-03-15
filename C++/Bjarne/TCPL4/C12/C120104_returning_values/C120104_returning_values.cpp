// C120104_returning_values.cpp 
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

// (1) prefix and suffix return type declaration
string to_string(int a);              // prefix return type
auto to_string(int a) -> string;      // suffix return type

// (2) use suffix return type in function template
template<typename T, typename U>
auto product(const vector<T>& x, const vector<U>& y) -> decltype(x* y);

// int f1() {}                  // error: no value returned
void f2() {}                    // OK
int f3() { return 1; }          // OK
// void f4() { return 1; }      // error: return value in void function
// int f5() { return; }         // error: return value missing
void f6() { return; }            // OK

// a return value is specified by a return-statement
int fac1(int n) {
  return (n > 1) ? n * fac1(n - 1) : 1;
}

// more than one return-statement
int fac2(int n) {
  if(n > 1)
    return n * fac2(n - 1);
  return 1;
}

void fac_demo() {
  std::cout << "fac1 = " << fac1(5) << '\n';
  std::cout << "fac2 = " << fac2(5) << '\n';
}

// don't return pointer to function local variable
int* fp() {
  int local = 1;
  // ...
  return &local;      // bad return value
}

// don't return reference to function local variable
int& fr() {
  int local = 1;
  // ...
  return local;       // bad return value
}

void g(int* p) {
}

void h(int* p) {
  // ...
  return g(p);        // OK: equivalent to "g(p); return;"
}

void return_void() {
  int i = 1;
  h(&i);
}

int main() {
  fac_demo();
  return_void();
}
