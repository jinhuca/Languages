// C110603_transform.cpp 
#include "../algostuff.hpp"

int main() {
  std::vector<int> coll1;
  std::list<int> coll2;
  INSERT_ELEMENTS(coll1, 1, 9);
  PRINT_ELEMENTS(coll1, "coll1: ");

  // negate all elements of coll1
  std::transform(coll1.cbegin(), coll1.cend(),    // source range
                 coll1.begin(),                   // destination start
                 std::negate<int>()               // operation
  );
  PRINT_ELEMENTS(coll1, "negated: ");
}
