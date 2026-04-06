// C190300_string_class.cpp 
#include <iostream>
#include <vector>
#include "String.h"

using std::vector;
using std::cout;

int hash(const String& s) {
  if(s.size() == 0) return 0;
  int h{s[0]};                      // unchecked access to s
  for(int i{1}; i < s.size(); ++i)
    h ^= s[i] >> 1;                 // unchecked access to s
  return h;
}

void print_in_order(const String& s, const vector<int>& index) {
  for(const auto x : index) {
    cout << s.at(x) << '\n';        // checked access to s
  }
}

int main() {
  String s{"abcd"};
  cout << s << '\n';
}
