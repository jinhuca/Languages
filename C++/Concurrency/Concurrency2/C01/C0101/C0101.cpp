// C0101.cpp
#include <iostream>
#include <thread>

void hello()
{
  std::cout << "Hello Concurrent World!\n";
}

int main()
{
  std::thread t(hello);
  std::cout << "Hello from main!\n";
  t.join();
}
