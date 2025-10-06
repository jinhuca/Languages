export module Assoc;

import std;

export struct Assoc {
  std::vector<std::pair<std::string, int>> vec;   // vector of {name, value} pairs
  const int& operator[](const std::string&) const;
  int& operator[](const std::string&);
};