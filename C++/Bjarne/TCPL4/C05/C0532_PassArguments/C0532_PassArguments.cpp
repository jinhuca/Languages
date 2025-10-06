// C0532_PassArguments.cpp
import std;

void f(std::vector<double>& v) {    // function to do something with v
  for (const auto& e : v)
    std::cout << e << ' ';
}

struct F {                          // function object: do something with v
  std::vector<double>& v;
  F(std::vector<double>& vv) : v { vv } {}
  void operator()() const {
    for (const auto& e : v)
      std::cout << e << ' ';
  }
};

int main() {
  std::vector<double> some_vec { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::vector<double> vec2 { 10, 11, 12, 13, 14 };

  std::thread t1 { f,  std::ref(some_vec) };
  std::thread t2 { F{vec2} };

  t1.join();
  t2.join();
}
