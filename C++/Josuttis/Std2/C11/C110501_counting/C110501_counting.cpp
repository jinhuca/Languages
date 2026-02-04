// C110501_counting.cpp 
#include "../algostuff.hpp"

int main() {
  std::vector<int> coll;
  int num;
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // count elements with value 4
  num = std::count(
    coll.cbegin(), coll.cend(),     // range
    4                               // value to be counted
  );
  std::cout << "number of elements with value 4:    " << num << std::endl;

  // count elements with even value
  num = std::count_if(
    coll.cbegin(), coll.cend(),     // range
    [](int elem) {                  // criterion
      return elem % 2 == 0;
    });
  std::cout << "number of elements with even value: " << num << std::endl;

  // count elements with value greater than 4
  num = std::count_if(
    coll.cbegin(), coll.cend(),     // range
    [](int elem) {                  // criterion
      return elem > 4;
    });
  std::cout << "number of elements greater than 4:  " << num << std::endl;
}
