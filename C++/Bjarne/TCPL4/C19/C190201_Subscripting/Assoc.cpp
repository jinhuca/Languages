import std;
import Assoc;

// search for s: return a reference to its value if found;
// otherwise, make a new pair {s, 0} and return a reference to its value
int& Assoc::operator[](const std::string& s) {
  for(auto& x : vec)
    if(s == x.first) return x.second;
  vec.push_back({s,0});          // initial value: 0
  return vec.back().second;      // return last element
}