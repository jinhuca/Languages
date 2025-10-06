// P214.cpp

//#include <iostream>
//#include <chrono>
//#include <thread>
import std;

using namespace std::chrono;
using namespace std::chrono_literals;

int main()
{
  const auto t0 = system_clock::now();
  std::this_thread::sleep_for(10ms + 33us);
  const auto t1 = system_clock::now();
  std::cout << t1 - t0 << '\n';
}
