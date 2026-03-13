// C110303_unqualified_lists.cpp 
#include <iostream>
#include <initializer_list>
#include <utility>
#include <numeric>
#include <vector>

struct Matrix {
  double x, y;

  double operator[](std::pair<double, double> pair) {
    return pair.first;
  }
};

int f(double d, Matrix& m) {
  int v{7};             // initializer (direct initialization)
  int v2 = {7};         // initializer (copy initialization)
  int v3 = m[{2, 3}];   // m takes value pairs as subscripts

  v = {8};              // right-hand operand of assignment
  // v += {88};         // right-hand operand of assignment, not allowed here
  // {v} = 9;           // error: not left-hand operand of assignment
  // v = 7 + {10};      // error: not an operand of a non-assignment operator
  f({10.1}, m);         // function argument
  return {11};          // return value
}

int high_value(std::initializer_list<int> val) {
  int high = std::numeric_limits<int>::lowest();
  if(val.size() == 0) return high;
  for(auto x : val)
    if(x > high) high = x;
  return high;
}

void use_initializer_list() {
  int v1 = high_value({1,2,3,4,5,6,7});
  int v2 = high_value({-1,2,v1,4,-9,20,v1});
}

void deduce_element_types_from_unqualified_list() {
  // auto x0 = {};        // error (no element type) - no element type can be deduced
  auto x1 = {1};          // element type deduced as int - so initializer_list<int> for {1}
  auto x2 = {1,2};        // element type deduced as int - so initializer_list<int> for {1,2}
  auto x3 = {1,2,3};      // element type deduced as int - so initializer_list<int> for {1,2,3}
  // auto x4 = {1,2.0};   // error: non-homogeneous list -
}

template<typename T>
void f(T t) {}

void no_deduce_for_plain_template_type() {
  // f({});               // error: type of initializer is unknown
  // f({1});              // error: an unqualified list does not match "plain T"
  // f({1,2});            // error: an unqualified list does not match "plain T"
  // f({1,2,3});          // error: an unqualified list does not match "plain T"
}

template<typename T>
void f2(const std::vector<T>& rv) { 
}

void no_deduce_element_type_in_ontainer_for_plain_template() {
  // f2({1,2,3});               // error: cannot deduce T
  // f2({"Kona", "Sidney"});    // error: cannot deduce T
  f2(std::vector<int>{1, 2, 3});                    // OK
  f2(std::vector<std::string>{"Kona", "Sidney"});   // OK
}

int main() {
  use_initializer_list();
  deduce_element_types_from_unqualified_list();
  no_deduce_for_plain_template_type();
  no_deduce_element_type_in_ontainer_for_plain_template();
}
