// C0454_Predicates.cpp
import std;

struct Greater_than {
  int val;
  Greater_than(int v) :val { v } {}
  bool operator()(const std::pair<std::string, int>& r) { return r.second > val; }
};

void f(std::map<std::string, int>& m) {
  auto p = std::find_if(m.begin(), m.end(), Greater_than(15));
}

int main() {
  std::map<std::string, int> m1 {
  {"john",23},
  {"doe",13} };
  f(m1);
}
