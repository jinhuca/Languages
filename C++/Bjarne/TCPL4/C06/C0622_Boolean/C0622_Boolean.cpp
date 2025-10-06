// C0622_Boolean.cpp
import std;

void f(int a, int b) {
  bool b1 { a == b };   // a bool is used to express the result of logical operation
  // ...
}

void g() {    // convert to bool
  bool b1 = 7;        // 7 != 0, so b1 becomes true
  //bool b2 { 7 };      // error, no narrowing conversion by universal initialization form.
  bool b2 { 7 != 0 };
  // or
  int i = 7;
  bool b3 { i != 0 };

  int i1 = true;      // i1 becomes 1
  int i2 { true };    // i2 becomes 1
}

void h() {
  bool b1 = true;
  int i1 = 2;
  auto r1 = b1 | i1;    // bool is converted to int in bitwise operation.
}

void k(int* p) {
  bool b = p;       // narrows to true or false
  bool b2 { p != nullptr };
  if(p) {
    std::cout << "p is not null.\n";
  }
  else {
    std::cout << "p is null.\n";
  }
}

int main() {
  f(2, 3);
  h();
  int x = 1;
  int* p = &x;
  k(p);
  std::cout << sizeof(bool) << '\n';
}
