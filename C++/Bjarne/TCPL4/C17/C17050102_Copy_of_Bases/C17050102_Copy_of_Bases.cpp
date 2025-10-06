// C17050102_Copy_of_Bases.cpp 
import std;

struct B1 {
  B1(){}
  B1(const B1& b) {
  }
  // ...
};

struct B2 {
  B2(int x) :a { x } {}
  B2(const B2& x2) : a { x2.a } {
  }
  // ...
private:
  int a;
};

struct D :B1, B2 {  
  D(int i) : B1 {}, B2 { i }, m1 {}, m2 { 2 * i } {}
  D(const D& a) :B1 { a }, B2 { a }, m1 { a.m1 }, m2 { a.m2 } {}
  B1 m1;
  B2 m2;
};

void f() {
  D d { 1 };    // construct with in argument
  D dd { d };     // copy construct
}

int main() {
  f();
}
