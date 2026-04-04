// C170602_default_operations.cpp 
#include <iostream>
#include <string>
using std::string;

struct S {
  string a;
  int b;
};

S f(S arg) {
  S s0;           // default construction: {"",0}
  S s1{s0};       // default copy construction
  s1 = arg;       // default copy assignment
  return s1;      // default move construction
}

int main() {
  S arg;
  S result = f(arg);
}
