// C1104_for_each.cpp 
#include "..\algostuff.hpp"

void print(int elem) {
  std::cout << elem << ' ';
}

void pass_lambda() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);

  // call print() for each element in coll
  std::for_each(coll.cbegin(), coll.cend(),                   // range
    [](int elem) { std::cout << elem << ' '; });              // operation
}

void pass_function() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  // call print() for each element in coll
  std::for_each(coll.cbegin(), coll.cend(),                   // range
    print);                                                   // operation
}

void modify_elements() {
  std::vector<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  
  // add 10 to each element in coll 
  std::for_each(coll.begin(), coll.end(),                     // range
    [](int& elem) { elem += 10; });                           // operation
  PRINT_ELEMENTS(coll);

  // add value of first element to each element in coll
  std::for_each(coll.begin(), coll.end(),                     // range
    [first = coll.front()](int& elem) { elem += first; });    // operation
  PRINT_ELEMENTS(coll);
}

int main() {
  //pass_lambda();
  modify_elements();
}
