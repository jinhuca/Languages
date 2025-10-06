// C0533_ReturnResults.cpp 
import std;

void f(const std::vector<double>& v, double* result) {    // take input from v; place result in *res

}

class F {
public:
  F(const std::vector<double>& vv, double* p) :v { vv }, res { p } {}
  void operator()() {   // place result in *res

  }
private:
  const std::vector<double>& v;     // source of input
  double* res;                      // target for output/result
};

int main() {
  std::vector<double> some_vec { 1.1, 2.1, 55, 3, 12.6 };
  std::vector<double> vec2;

  double res1;
  double res2;

  std::thread t1 { f, std::cref(some_vec), &res1 };
  std::thread t2 { F{vec2, &res2} };

  t1.join();
  t2.join();

  std::cout << res1 << ' ' << res2 << '\n';
}
