// C110604_swap_elements.cpp 
#include "..\algostuff.hpp"

int main() {
  std::vector<int> coll1;
  std::deque<int> coll2;

  INSERT_ELEMENTS(coll1, 1, 9);
  INSERT_ELEMENTS(coll2, 11, 23);

  PRINT_ELEMENTS(coll1, "coll1: ");
  PRINT_ELEMENTS(coll2, "coll2: ");

  // swap elements of coll1 with corresponding elements of coll2
  std::deque<int>::iterator pos;
  pos = std::swap_ranges(
    coll1.begin(), coll1.end(),   // first range
    coll2.begin()                 // second range
  );

  PRINT_ELEMENTS(coll1, "\ncoll1: ");
  PRINT_ELEMENTS(coll2, "coll2: ");
  if (pos != coll2.end()) {
    std::cout << "first unswapped element in coll2: " << *pos << std::endl;
  }

  // mirror first three with last three elements of coll2
  std::swap_ranges(
    coll2.begin(),                // first range start
    coll2.begin() + 3,            // first range end
    coll2.rbegin()                // second range start
  );
  PRINT_ELEMENTS(coll2, "\ncoll2: ");
}
