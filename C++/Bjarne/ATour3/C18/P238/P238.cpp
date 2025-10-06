// P238.cpp : Tasks and threads
import std;

void f() {
  std::cout << "function f() executed.\n";
}

struct F {
  void operator()() {
    std::cout << "function object invoked.\n";
  }
};

void use() {
  std::thread t1 { f };
  std::thread t2 { F() };
  t1.join();
  t2.join();
}

void use2()
{
  std::jthread t1 { f };
  std::jthread t2 { F() };
}

int main() {
  use();
}
