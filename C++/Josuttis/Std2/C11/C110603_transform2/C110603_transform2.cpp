// C110603_transform2.cpp : combine two sequences into one
#include "../algostuff.hpp"

int main() {
  std::vector<int> coll1;
  std::list<int> coll2;

  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1, "coll1: ");

  // square each element of coll1
  std::transform(
    coll1.cbegin(), coll1.cend(),     // first source range
    coll1.cbegin(),                   // second source range
    coll1.begin(),                    // destination range
    std::multiplies<int>());          // operation
  PRINT_ELEMENTS(coll1, "squared: ");

  // add each element traversed forward with each element traversed backward
  // and insert the results into coll2
  std::transform(
    coll1.cbegin(), coll1.cend(),     // first source range
    coll1.crbegin(),                  // second source range
    std::back_inserter(coll2),        // destination start
    std::plus<int>());                // operation
  PRINT_ELEMENTS(coll2, "coll2: ");

  // print differences of two corresponding elements
  std::cout << "diff:  ";
  std::transform(
    coll1.cbegin(), coll1.cend(),     // first source range
    coll2.cbegin(),                   // second source range
    std::ostream_iterator<int>(std::cout, " "), // destination range start
    std::minus<int>());               // operation
}
