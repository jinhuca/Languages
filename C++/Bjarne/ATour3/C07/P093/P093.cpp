import std;

template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v) {
  for(const auto& x : s) {
    v += x;
  }
  return v;
}

void user(const std::vector<int>& vi, const std::list<double>& ld, const std::vector<std::complex<double>>& vc) {
  int x = sum(vi, 0);                         // the sum of a vector of ints (add ints)
  std::cout << "sum of vi: " << x << '\n';
  double d = sum(vi, 0.0);                    // the sum of a vector of ints (add doubles)
  std::cout << "sum of vi: " << d << '\n';
  double e = sum(ld, 0.0);                    // the sum of a list of doubles
  std::cout << "sum of ld: " << e << '\n';
  auto z = sum(vc, std::complex(0.0, 0.0));   // the sum of a vector of complex<double> s
  std::cout << "sum of vc: " << z << '\n';
}

int main() {
  std::vector<int> vi { 1, 2, 3, 4, 5, 6 };
  std::list<double> ld { 1.2, 2.3, 3.4, 4.5 };
  std::vector<std::complex<double>> vc { { 1.5, 2.1 }, { 5.6, 7.1 }, { 9.1, 12.1 } };
  user(vi, ld, vc);
}
