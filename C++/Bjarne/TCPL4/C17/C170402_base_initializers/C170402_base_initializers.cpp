// C170402_base_initializers.cpp 
#include <iostream>

struct B1 { B1(); };       // has default constructor
struct B2 { B2(int); };    // no default constructor

struct D1 : B1, B2 {
  D1(int i) :B1{}, B2{i} {}
};

struct D2 :B1, B2 {
  D2(int i) :B2{i} {}     
};

struct D3 :B1, B2 {
  // D1(int i) {}            // error: B2 requires an int initializer
};

int main() {
}
