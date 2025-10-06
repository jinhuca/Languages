// P113.cpp : Abstraction using templates
import std;

double sum(const std::vector<int>& v) {
  double res = 0;
  for(auto x : v) {
    res += x;
  }
  return res;
}

void useSum() {
  std::vector<int> v1 { 1,3,5,11,3,5,10 };
  std::cout << sum(v1) << '\n';
}

template<typename Val>
concept Arithmetic = std::is_arithmetic_v<Val>;

template<typename Iter>
concept Iterator = std::forward_iterator;

template<Iterator T, Arithmetic V>
auto accumulate(T first, T last, V res) -> V {
  for(auto p = first; p != last; ++p) {
    res += *p;
  }
  return res;
}

void useConcept() {
  std::list<int> lst = { 1, 2, 3, 4, 5 };
  auto result = accumulate(std::begin(lst), std::end(lst), 0);
  std::cout << "Result = " << result << '\n';
}

int main() {
  //useSum();
  useConcept();
}
