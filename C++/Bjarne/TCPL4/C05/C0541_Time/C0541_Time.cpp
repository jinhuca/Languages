// C0541_Time.cpp
#include <chrono>
import std;

void do_work() {
  std::cout << "Hello, world!\n";
}

void f() {
  auto t0 = std::chrono::high_resolution_clock::now();
  do_work();
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout << "The work took "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count()
    << " nano seconds\n";
}

int main() {
  f();
}
