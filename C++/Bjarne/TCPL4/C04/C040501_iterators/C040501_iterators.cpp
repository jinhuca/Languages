// C0451_Iterators.cpp 
import std;

bool has_c(const std::string& s, char c) {    // does s contain the character c?
  auto p = std::find(s.begin(), s.end(), c);
  if(p != s.end()) {
    return true;
  }
  return false;
}

bool has_c2(const std::string& s, char c) {
  return std::ranges::find(s, c) != s.end();
}

void simple_ostream_demo() {
  std::string s = "hello, world!\n";
  if(has_c2(s, 'w'))
    std::cout << "contains w";
  else
    std::cout << "no";
}

std::vector<std::string::iterator> find_all(std::string& s, char c) {   // find all occurrences of c in s
  std::vector<std::string::iterator> res;
  for(auto p = s.begin(); p != s.end(); ++p)
    if(*p == c)
      res.push_back(p);
  return res;
}

template<typename C, typename V>
std::vector<typename C::iterator> find_all(C& c, V v) {
  std::vector<typename C::iterator> res;
  for(auto p = c.begin(); p != c.end(); ++p)
    if(*p == v)
      res.push_back(p);
  return res;
}

template<typename T>
using Iterator = typename T::iterator;

template<typename C, typename V>
std::vector<Iterator<C>> find_all2(C& c, V v) {
  std::vector<Iterator<C>> res;
  for(auto p = c.begin(); p != c.end(); ++p)
    if(*p == v)
      res.push_back(p);
  return res;
}

void test() {
  std::string m { "Mary had a little lamb" };
  for(auto p : find_all2(m, 'a'))
    if(*p != 'a')
      std::cerr << "string bug!\n";
}

int main() {
  std::string s = "hello, world!";
  auto v1 = find_all(s, 'o');
  test();
}
