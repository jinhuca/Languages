// Ex01_02_Function_Object.cpp : A basic print function object.
#include <algorithm>
#include <iostream>
#include <vector>

struct Printer {
  void operator()(int x) const {
    std::cout << x << '\n';
  }
};

void use_printer() {
  Printer printer;
  printer(42);  // calls Printer::operator()(int)
  printer.operator()(42);  // same as above
}

void use_printer_as_param() {
  Printer printer;
  std::vector<int> v;
  v.push_back(1);    // no uniform initialization in C++03!
  v.push_back(2);    // push_back available only ...
  std::for_each(v.begin(), v.end(), printer);
}

int main() {
  use_printer();
  use_printer_as_param();
}
