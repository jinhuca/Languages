// C130503_exceptions_and_threads.cpp 
#include <iostream>
#include <exception>
#include <thread>
#include <future>

int main() {
  try {
    // ... do the work ...
  }
  catch(...) {
    std::promise<void> prom;
    prom.set_exception(std::current_exception());
  }
}