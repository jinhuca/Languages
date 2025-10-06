// C1302Iterators.cpp
import std;

bool has_c(const std::string& s, char c) {
  auto p = std::find(s.begin(), s.end(), c);
  if (p != s.end())
    return true;
  else
    return false;
}

bool has_c_2(const std::string& s, char c) {
  return std::ranges::find(s, c) != s.end();
}

void test1() {
  std::string s1 = "Hello, World!";
  std::cout << std::boolalpha;
  std::cout << "Does string "
    << s1 << " has character o" << " = " << has_c(s1, 'o') << '\n';
}

std::vector<std::string::iterator> find_all(std::string& s, char c) {
  std::vector<std::string::iterator> res;
  for (auto p = s.begin(); p != s.end(); ++p) {
    if (*p == c)
      res.push_back(p);
  }
  return res;
}

void test2() {
  std::string m { "Mary had a little lamb" };
  for (auto p : find_all(m, 'a'))
    if (*p != 'a')
      std::cerr << "a bug!\n";
}

template<typename C, typename V>
std::vector<typename C::iterator> find_all(C& c, V v) {
  std::vector<typename C::iterator> result;
  for (auto p = c.begin(); p != c.end(); ++p) {
    if (*p == v)
      result.push_back(p);
  }
  return result;
}

std::ostream_iterator<std::string> oo { std::cout };    // write strings to cout

int main() {
  //test1();
  //test2();
  *oo = "Hello, ";
  ++oo;
  *oo = "world!\n";
}
