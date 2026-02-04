// C110503_search_elements.cpp 
#include "../algostuff.hpp"

void find1() {
  std::list<int> coll;
  INSERT_ELEMENTS(coll, 1, 9);
  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // find first element with value 4
  std::list<int>::iterator pos1;
  pos1 = std::find(
    coll.begin(), coll.end(),     // range
    4                             // value to be found
  );

  // find second element with value 4
  // - note: continue the search behind the first found element
  std::list<int>::iterator pos2;
  if (pos1 != coll.end()) {
    pos2 = std::find(
      ++pos1, coll.end(),         // range
      4                           // value to be found
    );
  }

  // print all elements from first to second 4 (both included)
  // - note: now we need the position of the first 4 again (if any)
  if (pos1 != coll.end() && pos2 != coll.end()) {
    std::copy(--pos1, ++pos2,
      std::ostream_iterator<int>(std::cout, " ")
    );
    std::cout << std::endl;
  }
}

void find2() {
  std::vector<int> coll;
  std::vector<int>::iterator pos;

  INSERT_ELEMENTS(coll, 1, 9);
  PRINT_ELEMENTS(coll, "coll: ");

  // find first element greater than 3
  pos = std::find_if(
    coll.begin(), coll.end(),                                   // range
    std::bind(std::greater<int>(), std::placeholders::_1, 3)    // criterion
  );

  // print its position
  std::cout << "the "
    << std::distance(coll.begin(), pos) + 1
    << ". element is the first element greater than 3"
    << std::endl;

  // find first element divisible by 3
  pos = std::find_if(
    coll.begin(), coll.end(),                                   // range
    [](int elem) { return elem % 3 == 0; }                      // criterion
  );
  std::cout << "the "
    << std::distance(coll.begin(), pos) + 1
    << ". element is the first element divisible by 3"
    << std::endl;

  // find first element not less than 5
  pos = std::find_if_not(
    coll.begin(), coll.end(),                                   // range
    std::bind(std::less<int>(), std::placeholders::_1, 5)       // criterion
  );
  std::cout << "first value >=5:  " << *pos << std::endl;
}

int main() {
  //find1();
  find2();
}
