// C11040302_namespace_names.cpp 
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

template<typename U, typename V>
std::ostream& operator<<(std::ostream& os, const std::pair<U, V>& p) {
  return os << '{' << p.first << ',' << p.second << '}';
}

void print_all(const std::map<std::string, int>& m, const std::string& label) {
  std::cout << label << ":\n{\n";
  std::for_each(m.begin(), m.end(),
    [](const std::pair<std::string, int>& p) {std::cout << p << '\n'; });
  std::cout << "}\n";
}

int main() {
  std::map<std::string, int> m {
    {"chendu", 123}, {"shanghai",321}, {"beijing", 456}
  };
  print_all(m, "cities");
}
