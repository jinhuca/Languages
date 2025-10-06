// P241.cpp : Chapter 18 - Sharing Data
import std;

std::mutex m;     // controlling mutex
int sh;           // shared data

void f() {
  std::scoped_lock<std::mutex> lck { m };   // acquire mutex
  sh += 7;                                     // manipulate shared data
}                                              // release mutex implicitly

int main() {
  std::cout << "shared data before = " << sh << '\n';
  f();
  std::cout << "shared data after = " << sh << '\n';
}
