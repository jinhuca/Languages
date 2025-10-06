// C06361_Auto.cpp
import std;

void f() {
  int a1 = 123;
  char a2 = 123;
  auto a3 = 123;
}

template<typename T>
void f1(std::vector<T>& arg) {
  for(typename std::vector<T>::iterator p = arg.begin(); p != arg.end(); ++p)
    *p = 7;
  for(auto p = arg.begin(); p != arg.end(); ++p)
    *p = 7;
}

void g(std::complex<double> d) {
  // ...
  auto max = d + 7.0;
  //double min = d - 2.9;
  // ...
}

void k(int& v) {
  auto x = v;   // x is an int (not an int&)
  auto& y = v;  // y is an int&
}

int main() {
  f();
  auto d = std::complex<double> { 1,2 };
  g(d);
  int a = 1;
  k(a);
}
