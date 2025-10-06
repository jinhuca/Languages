// C0531.cpp
import std;

void f() {          // function to represent a TASK
  std::cout << "Hello ";
}

struct F {                // function object to represent a Task
  void operator()() {
    std::cout << "Parallel World!\n";
  };
};

void user() {
  std::thread t1 { f };
  std::thread t2 { F() };
  t1.join();
  t2.join();
}

int main() {
  user();
}
