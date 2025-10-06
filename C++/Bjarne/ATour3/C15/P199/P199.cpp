// P199.cpp
import std;
#include "Student.h"

struct S {
  S(int id, std::string sd, double dd) :
    i { id }, s { sd }, d { dd } {}

  int i;
  std::string s;
  double d;
};

void f() {
  auto p1 = std::make_shared<S>(1, "Kitty", 4.56);
  auto p2 = std::make_unique<S>(2, "Oz", 7.32);
  std::cout << p1->d << std::endl;
}

void g() {
  Student s1("jon", 21);
  auto s2 = std::make_shared<Student>("doe", 19);
  auto s3 = std::make_shared<Student>("Skeet", 20);
}

int main() {
  f();
  g();
}
