// C110301_implementation_model.cpp 
#include <iostream>
#include <vector>
#include <initializer_list>

void constructor_with_initializer_list() {
  std::vector<double> v1 = {1, 2, 3.14};

  // the above initialization is implemented as 
  const double temp[] = {double{1}, double{2}, 3,14};
  const std::initializer_list<double> tmp(temp, sizeof((temp) / sizeof(double)));
  std::vector<double> v2(tmp);
}

void initializer_list_is_immutable() {
  std::initializer_list<int> lst{1,2,3};
  std::cout << *lst.begin() << '\n';
  //*lst.begin() = 2;                   // error: lst is immutable
  std::cout << *lst.begin() << '\n';
}

void initialize_aggregate() {
  int arr[] = {1,2,3};
}

int main() {
  constructor_with_initializer_list();
  initializer_list_is_immutable();
  initialize_aggregate();
}
