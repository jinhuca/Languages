import std;

template<typename Seq, typename Value>
Value sum(const Seq& s, Value v) {
  for(const auto& x : s)
    v += x;
  return v;
}

template<typename T>
concept integral = std::is_integral_v<T>;

template<typename T>
concept ILabel = requires(T v) {
  { v.buildHtml() }->std::convertible_to<std::string>;
};


template<typename T>
  requires std::integral<T> || std::floating_point<T>
constexpr double average(std::vector<T> const& vec) {
  const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
  return sum / static_cast<double>(vec.size());
}

int main() {
  const std::vector<double> seq = { 1.2, 3.4, 5.1, 4,2 };
  double v = 0.0;
  std::cout << average(seq) << '\n';
  std::cout << sum(seq, v);
}
