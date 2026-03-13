// C110401_implement_lambda.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

void print_modulo(const std::vector<int>& v, std::ostream& os, int m) {
  std::for_each(std::begin(v), std::end(v), [&os, m](int x) {
    if(x % m == 0) os << x << '\n';
  });
}

void use_lambda() {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};
  print_modulo(v, std::cout, 3);
}

class Module_print {
  std::ostream& os;
  int m;
public:
  Module_print(std::ostream& s, int mm) :os{s}, m{mm} {}
  void operator()(int x) const {
    if(x % m == 0) os << x << '\n';
  }
};

void print_modulo_fo(const std::vector<int>& v, std::ostream& os, int m) {
  std::for_each(std::begin(v), std::end(v), Module_print(os, 3));
}

void use_function_object() {
  std::vector<int> v{1,2,3,4,5,6,7,8,9};
  print_modulo_fo(v, std::cout, 3);
}

int main() {
  use_lambda();
  use_function_object();
}
