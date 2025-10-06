// C0101_Motivation.cpp 
import std;

std::vector<std::string> create_and_insert() {
  std::vector<std::string> coll;      // create vector of strings
  coll.reserve(3);                    // reserve memory for 3 elements
  std::string s = "data";             // create string object

  coll.push_back(s);                  // insert string object
  coll.push_back(s + s);              // insert temporary string
  coll.push_back(s);                  // insert string

  return coll;                        // return vector of strings
}

int main() {
  std::vector<std::string> v;         // create empty vector of strings
  v = create_and_insert();            // assign vector of strings
}
