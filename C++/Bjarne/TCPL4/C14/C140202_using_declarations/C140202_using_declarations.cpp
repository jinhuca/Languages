// C140202_using_declarations.cpp
#include <string>
#include <sstream>
#include <vector>

// split s into its whitespace-separated substrings
std::vector<std::string> split(const std::string& s) {
  std::vector<std::string> res;
  std::istringstream iss(s);
  for(std::string buf; iss >> buf;)
    res.push_back(buf);
  return res;
}

using std::string;    // use "string" to mean "std::string"

std::vector<string> split2(const string& s) {
  std::vector<string> res;
  std::istringstream iss(s);
  for(string buf; iss >> buf;)
    res.push_back(buf);
  return res;
}

int main() {
  
}
