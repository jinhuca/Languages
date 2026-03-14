// C110402_alternatives_to_lambda.cpp 
#include <iostream>
#include <vector>
#include <algorithm>

// output v[i] to os if v[i]%m==0
void print_modulo(const std::vector<int>& v, std::ostream& os, int m) {
  // (1) define a local class with operator() definition
  class Module_print {
    std::ostream& os;
    int m;
  public:
    Module_print(std::ostream& s, int mm) :os {s}, m {mm} {}
    void operator()(int x) const {
      if(x % m == 0) os << x << '\n';
    }
  };

  // (2) pass an object of local class to the function
  std::for_each(begin(v), end(v), Module_print {os, m});
}

// use named lambda expression
void print_modulo_lambda(const std::vector<int>& v, std::ostream& os, int m) {
  // (1) define a lambda expression, and name it
  auto module_print_lambda = [&os, m](int x) {if(x % m == 0)os << x << '\n'; };
  // (2) pass the lambda to the function
  std::for_each(begin(v), end(v), module_print_lambda);
}

int main() {
  std::vector<int> v {1,2,3,4,5,6,7,8,9};
  print_modulo(v, std::cout, 3);
  print_modulo_lambda(v, std::cout, 3);
}
