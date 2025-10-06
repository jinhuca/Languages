// C170303_Default_Constructors.cpp
import std;

class Vector {
public:
  //Vector() {    // default constructor: no elements
  //  std::cout << "default constructor invoked.\n";
  //}

  Vector(const char* p = "") {
    std::cout << "non-default constructor with default argument.\n";
  }
};

void f() {
  Vector v1;
  Vector v2 {};
}

class String {
public:
  String(const char* p = "") {}
  //String() {}
};

void g() {
  String s1;
  String s2 {};
}

int main() {
  f();
}
