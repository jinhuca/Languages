// C020302_Auto_Template.cpp 
import std;

void addValueInto(const auto& val, auto& coll) { // OK: C++20
  std::inserter(coll, coll.end()) = val;
}

//template<typename Coll>
//  requires std::ranges::random_access_range<Coll>
//void addValueInto(const auto& val, Coll& coll) { // OK: C++20
//  coll.push_back(val);
//}

int main() {
  std::vector<int> coll;
  addValueInto(42, coll); 
  for(const auto& elem : coll) {
    std::cout << elem << '\n';
  }
}
