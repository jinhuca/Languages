// P250.cpp : coroutine
import std;

std::generator<int> fibonacci_generator() {   // generate Fibonacci numbers
  int a = 0;
  int b = 1;
  co_yield a;
  co_yield b;
  while(true) {
    auto next = a + b;
    co_yield next;                  // save state, return value, and wait
    a = b;
    b = next;
  }
}

void use(int max) {
  for(int num : fibonacci_generator() | std::views::take(max)) {
    std::cout << num << ", ";
  }
}

int main() {
  std::cout << "Fibonacci numbers: \n";
  use(10);
}
