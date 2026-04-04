// C17050102_copy_bases.cpp 
#include <iostream>

struct B1 {
  B1();
  B1(const B1&);
};

struct B2 {
  B2(int);
  B2(const B2&);
};

struct D :B1, B2 {
  D(int i) : B1{}, B2{i}, m1{}, m2{2 * i} {}
  D(const D& a) : B1{a}, B2{a}, m1{a.m1}, m2{a.m2} {}
  B1 m1;
  B2 m2;
};

int main() {
  
}
