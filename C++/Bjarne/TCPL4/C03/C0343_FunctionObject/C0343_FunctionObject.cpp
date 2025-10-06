// C0343_FunctionObject.cpp
import std;

template<typename T>
class Less_than {
  const T val;      // value to compare against
public:
  Less_than(const T& v) :val { v } {}
  bool operator()(const T& x) const { return x < val; }
};

template<typename C, typename P>
int count(const C& c, P pred) {
  int cnt = 0;
  for(const auto& x : c) {
    if(pred(x))
      ++cnt;
  }
  return cnt;
}

void f(const std::vector<int>& vec, int s) {
  std::cout << count(vec, Less_than<int>{s}) << '\n';
}

void f_lambda(const std::vector<int>& vec, int s) {
  std::cout << count(vec, [&](int a) { return a < s; });
}

int main() {
  std::vector<int> v1 { 1,2,3,4,5,6,7,8,9 };
  f(v1, 4);
  f_lambda(v1, 4);
}
