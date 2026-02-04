// C110603_transform.cpp 
#include "../algostuff.hpp"

int main() {
  std::vector<int> coll1;
  std::list<int> coll2;
  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1, "coll1: ");

  // negate all elements of coll1
  std::transform(
    coll1.cbegin(), coll1.cend(),                                   // source range
    coll1.begin(),                                                  // destination start
    std::negate<int>()                                              // operation
  );
  PRINT_ELEMENTS(coll1, "negated: ");

  // transform elements of coll1 into coll2 with ten times their value
  std::transform(
    coll1.cbegin(), coll1.cend(),                                   // source range
    std::back_inserter(coll2),                                      // destination start
    std::bind(std::multiplies<int>(), std::placeholders::_1, 10));  // operation
  PRINT_ELEMENTS(coll2, "coll2: ");

  // print coll2 negatively and in reverse order
  std::transform(
    coll2.crbegin(), coll2.crend(),                                // source range
    std::ostream_iterator<int>(std::cout, " "),                    // destination start
    [](int elem) { return -elem; }                                 // operation
  );
}
