// C010201_Struct_Class.cpp 
#include <iostream>

struct B {
  int a = 1;
  int b = 2;
};

struct D1 : B {
};

struct D2 : B {
  int c = 3;
};

int main() {
  auto [x, y] = D1{};       // OK
  //auto [i, j, k] = D2{};    // compile-time error
}
