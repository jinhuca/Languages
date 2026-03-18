// C130107_exceptions_and_efficiency.cpp 
#include <iostream>
#include <string>
using std::string;
using std::cin;

void g(int i) noexcept {
}

void h(const string& s) noexcept {
}

void f() {
  string buf;
  cin >> buf;
  // ...
  g(1);
  h(buf);
}

int main() {
  std::cout << "Hello World!\n";
}
