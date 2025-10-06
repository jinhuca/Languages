// C05353_async.cpp 
import std;

double accum(double* beg, double* end, double init) {
  // compute the sum of [beg:end) starting with the initial value int
  return std::accumulate(beg, end, init);
}

double comp4(std::vector<double>& v) {
  // spawn many tasks if v is large enough
  if (v.size() < 10000)
    return std::accumulate(v.begin(), v.end(), 0.0);

  auto v0 = &v[0];
  auto sz = v.size();

  auto f0 = std::async(accum, v0, v0 + sz / 4, 0);
  auto f1 = std::async(accum, v0 + sz / 4, v0 + sz / 2, 0);
  auto f2 = std::async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0);
  auto f3 = std::async(accum, v0 + sz * 3 / 4, v0 + sz, 0);

  return f0.get() + f1.get() + f2.get() + f3.get();
}

int main() {
  std::cout << "Hello World!\n";
}
