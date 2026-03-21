// C13050202_catch_every_exception.cpp 
#include <exception>

void catch_std_exception() {
  try {
    // ... do something ...
  }
  catch(std::exception& err) {  // handle every standard-library exception
    // ... clean up ...
    throw;
  }
}

void catch_all() {
  try {
    // ... something ...
  }
  catch(...) {   // handle every exception
    // ... clean up ...
    throw;
  }
}

int main() {
  catch_std_exception();
  catch_all();
}
