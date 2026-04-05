// C190201_subscripting.cpp 
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::pair;
using std::string;
using std::cout;
using std::cin;

struct Assoc {
  vector<pair<string, int>> vec;
  const int& operator[](const string&) const;
  int& operator[](const string&);
};

int& Assoc::operator[](const string& s) {
  for(auto& x : vec)
    if(s == x.first) return x.second;
  vec.push_back({s, 0});
  return vec.back().second;
}

const int& Assoc::operator[](const string& s) const {
  for(const auto& x : vec)
    if(s == x.first) return x.second;
  throw std::out_of_range("index");
}

int main() {
  Assoc values;
  for(string buf; cin >> buf;)
    ++values[buf];
  for(auto& x : values.vec)
    cout << '{' << x.first << ',' << x.second << "}\n";
}


