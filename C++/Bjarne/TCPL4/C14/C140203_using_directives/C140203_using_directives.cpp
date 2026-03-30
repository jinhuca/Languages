// C140203_using_directives.cpp 
#include <string>
#include <sstream>
#include <vector>
#include "Text_lib.h"
#include "Graph_lib.h"

using namespace std;    // make every name from std available without qualification

// split a string into whitespace-separated substrings
vector<string> split(const string& s) {
  vector<string> res;
  istringstream iss(s);
  for(string buf; iss >> buf;)   // read whitespace-separated tokens
    res.push_back(buf);
  return res;
}

using namespace Graph_lib;   // make every name from Graph_lib available without qualification
using namespace Text_lib;    // make every name from Text_lib available without qualification

int main() {
  auto res = split("This is a test of using directives");   // call split without qualification

  Glyph g1;   // use Glyph from Graph_lib without qualification
  vector<Shape*> vs;   // use vector from std without qualification

  Text t1;                            // error: ambiguous
  File* fp = open("my_shapes.txt");   // error: ambiguous
}
