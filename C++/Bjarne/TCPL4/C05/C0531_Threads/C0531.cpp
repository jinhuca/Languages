// C0531.cpp
import std;

void f() {                // function to represent a TASK
  std::cout << "function call.\n";
}

struct F {                // function object to represent a Task
  void operator()() {
    std::cout << "function object call.\n";
  };
};

void user() {
  auto lambda = []() {        // lambda to represent a Task
    std::cout << "lambda call.\n";
    };

  std::thread t1 { f };
  std::thread t2 { F() };
  std::thread t3 { lambda };
  t1.join();
  t2.join();
  t3.join();
}

int main() {
  user();
}
