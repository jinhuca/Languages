// C0201_if_initialization.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ofstream getLogStrm() {
  std::ofstream myStrm("fileName.txt");
  return myStrm;
}

int main() {
  std::vector<std::string> coll{ "hello" };
  if (std::ofstream strm = getLogStrm(); coll.empty()) {
    strm << "<no data>\n";
  }
  else {
    for (const auto& elem : coll) {
      strm << elem << '\n';
    }
  }
  // strm is out of scope.
}
