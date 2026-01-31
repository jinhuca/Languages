// C0304_thread_local.cpp 
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include "inlinethreadlocal.h"

void foo();

int main() {
  myThreadData.print("main() begin:");

  myThreadData.gName = "thread1 name";
  myThreadData.tName = "thread1 name";
  myThreadData.lName = "thread1 name";
  myThreadData.print("main() later:");

  std::thread t(foo);
  t.join();
  myThreadData.print("main() end:");
}

void foo() {
}
