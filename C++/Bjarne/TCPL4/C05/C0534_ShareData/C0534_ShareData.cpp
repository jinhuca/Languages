// C0534_ShareData.cpp
import std;

std::mutex m;     // controlling mutex
int sh;           // shared data

void f() {
  std::unique_lock<std::mutex> lck { m };   // acquire the mutex m
  sh += 7;                                      // manipulate shared data
}   // release mutex m implicitly

class Record {
public:
  std::mutex rm;
};

std::mutex m1, m2, m3;

void g() {
  std::unique_lock<std::mutex> lck1 { m1, std::defer_lock };    // defer_lock: don't yet try to acquire the mutex
  std::unique_lock<std::mutex> lck2 { m2, std::defer_lock };
  std::unique_lock<std::mutex> lck3 { m3, std::defer_lock };
  // ...
  std::lock(lck1, lck2, lck3);                    // acquire all three locks
  // ... manipulate shared data
}   // implicitly release all mutexes

int main() {
  std::cout << "Hello World!\n";
}
