// P0546.cpp algo/mismatch1.cpp
import std;

template <typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr = "") {
  std::cout << optstr;
  for (const auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> coll1 = { 1, 2, 3, 4, 5, 6 };
  std::list<int>   coll2 = { 1, 2, 4, 8, 16, 3 };

  PRINT_ELEMENTS(coll1, "coll1: ");
  PRINT_ELEMENTS(coll2, "coll2: ");

  // find first mismatch
  auto values = std::mismatch(
    coll1.cbegin(), coll1.cend(),     // first range
    coll2.cbegin());                  // second range
  if (values.first == coll1.end()) {
    std::cout << "no mismatch.\n";
  }
  else {
    std::cout << "first mismatch: "
      << *values.first << " and "
      << *values.second << '\n';
  }

  // find first position where the element of coll1 is not less
  // than the corresponding element of coll2
  values = std::mismatch(
    coll1.cbegin(), coll1.cend(),     // first range
    coll2.cbegin(),                   // second range
    std::less_equal<int>());          // criterion
  if (values.first == coll1.end()) {
    std::cout << "always less-or-equal\n";
  }
  else {
    std::cout << "not less-or-equal: "
      << *values.first << " and "
      << *values.second << '\n';
  }
}
