// C13050201_rethrow.cpp 
#include <iostream>

bool can_handle_it_completely = false;
void h() {
  try {
    // ... code that might throw an exception ...
  }
  catch(std::exception& err) {
    if(can_handle_it_completely) {
      // ... handle it ...
      return;
    }
    else {
      // ... do what can be done here ...
      throw;      // rethrow the exception
    }
  }
}

int main() {
  h();
}
