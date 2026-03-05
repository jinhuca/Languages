// C0951_Range_for.cpp 
import std;

int sum(std::vector<int>& v) {
  int s = 0;
  for (int x : v)
    s += x;
  return s;
}

int sum2(std::vector<int>& v) {
  int s = 0;
  for (auto p = v.begin(); p != v.end(); ++p)
    s += *p;
  return s;
}

void incr(std::vector<int>& v) {
  for (int& x : v)
    ++x;
}

template<typename T>
T accum(std::vector<T>& v) {
  T sum = 0;
  for (const T& x : v)
    sum += x;
  return sum;
}

int main() {
  std::vector<int> v1 { 3, 5, 1, 3, 6, 7, 8, 5, 4 };
  std::cout << sum(v1) << '\n';
  std::cout << sum2(v1) << '\n';
  std::cout << accum(v1) << '\n';
  incr(v1);
  std::cout << sum(v1) << '\n';
}
