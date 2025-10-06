// P120.cpp : 

import std;

void f() {
  std::string s { "C++ is a general-purpose programming language" };
  std::cout << s << std::endl;
}

long fibonacci(unsigned n) {
  if(n < 2)
    return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

void chrono_demo() {
  const auto start = std::chrono::steady_clock::now();
  const auto fb = fibonacci(42);
  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> elapsed_seconds = end - start;

  std::cout << "f(42) = " << fb << '\n' << "elapsed time: ";
  std::cout << elapsed_seconds << '\n';
}

void chrono_literals_demo() {
  using namespace std::chrono_literals;
  std::chrono::seconds halfmin = 30s;

  std::cout << "Half a minute is " << halfmin.count() << " seconds.\n"
    "A minute and a second is " << (1min + 1s).count() << " seconds.\n";

  std::chrono::duration moment = 0.1s;
  std::cout << "A moment is " << moment.count() << " seconds.\n"
    "And thrice as much is " << (moment + 0.2s).count() << " seconds.\n";
}

void complex_literals_demo() {
  using namespace std::literals;
  using namespace std::complex_literals;
  using namespace std::literals::complex_literals;

  constexpr auto c = 1.0 + 2.0i;
  std::cout << c << std::endl;
}

int main() {
  f();
  chrono_demo();
  chrono_literals_demo();
  complex_literals_demo();
}
