// C0201_if_initialization.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <mutex>

std::ofstream getLogStrm() {
  std::ofstream myStrm("fileName.txt");
  return myStrm;
}

std::vector<std::string> coll{ "hello" };

void if_initialize_1() {
  
  if (std::ofstream strm = getLogStrm(); coll.empty()) {
    strm << "<no data>\n";
  }
  else {
    for (const auto& elem : coll) {
      strm << elem << '\n';
    }
  }
  // strm is out of scope.
  // ...
}

void if_initialize_2() {
  static std::mutex mtx;
  if (std::lock_guard<std::mutex> lg{mtx}; !coll.empty()) {
    std::cout << coll.front() << '\n';
  }
}

int main() {

}
