// C052_ResourceManagement.cpp
import std;

namespace C052 {
  std::mutex m;       // used to protect access to shared data

  void f() {
    std::unique_lock<std::mutex> lck { m };   // acquire the mutex m
    // ... manipulate shared data ...
  }   // release m here
}

int main() {
  C052::f();
}
