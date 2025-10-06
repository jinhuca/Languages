// P0548.cpp : algo/lexicocmp1.cpp
import std;

template <typename T>
void INSERT_ELEMENTS(T& coll, int first, int last)
{
  for (int i = first; i <= last; ++i) {
    coll.insert(coll.end(), i);
  }
}

template <typename T>
void PRINT_ELEMENTS(const T& coll, const std::string& optcstr = "")
{
  std::cout << optcstr;
  for (auto elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;
}

template <typename T>
void PRINT_MAPPED_ELEMENTS(const T& coll, const std::string& optcstr = "")
{
  std::cout << optcstr;
  for (auto elem : coll) {
    std::cout << '[' << elem.first
      << ',' << elem.second << "] ";
  }
  std::cout << std::endl;
}

void printCollection(const std::list<int>& l) {
  PRINT_ELEMENTS(l);
}

bool lessForCollection(const std::list<int>& l1, const std::list<int>& l2) {
  return std::lexicographical_compare(l1.cbegin(), l1.cend(),     // first range
    l2.cbegin(), l2.cend());                                      // second range
}

int main()
{
  std::list<int> c1, c2, c3, c4;

  // fill all collections with the same starting values
  INSERT_ELEMENTS(c1, 1, 5);
  c4 = c3 = c2 = c1;
  
  // and now some differences
  c1.push_back(7);
  c3.push_back(2);
  c3.push_back(0);
  c4.push_back(2);

  // create collection of collections
  std::vector<std::list<int>> cc;
  cc.insert(cc.begin(), { c1, c2, c3, c4, c3, c1, c4, c2 });

  // print all collections
  std::for_each(cc.cbegin(), cc.cend(), printCollection);
  std::cout << '\n';

  // sort collection lexicographically
  std::sort(cc.begin(), cc.end(),           // range
    lessForCollection);                     // sort criterion

  // print all collections again
  std::for_each(cc.cbegin(), cc.cend(), printCollection);
}
