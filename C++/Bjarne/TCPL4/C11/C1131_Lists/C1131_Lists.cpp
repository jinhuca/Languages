// C1131_Lists.cpp 
import std;

void f() {
  std::vector<double> v { 1, 2, 3.14 };
  const double temp[] = { double{1}, double{2}, 3.14 };
  const std::initializer_list<double> tmp { 3, 2, 4.1 };
  std::vector<double> v1(tmp);
}

struct S { int a, b; };

void g() {
  S v { 7,8 };              // direct initialization of a variable
  v = S { 7,8 };            // assign using qualified list
  S* p = new S { 7,8 };     // construct on free store using qualified list
}

int main() {
  f();
  g();
}
