// C13050203_multiple_handlers.cpp
#include <iostream>
#include <exception>

void f_catch_exceptions_in_appropriate_order() {
  try {
    // ...
  }
  catch(std::ios_base::failure) {
    // ... handle any iostream error ...
  }
  catch(std::exception& e) {
    // ... handle any standard-library exception ...
  }
  catch(...) {
    // ... handle any other exception ...
  }
}

void g_catch_exceptions_in_wrong_order() {
  try {
    // ...
  }
  catch(...) {
    // ... handle every exception
  }
  //catch(std::exception& e) {    // compiler warns such mistake, even flag as error
    // ... handle any standard-library exception ...
  //}
  //catch(std::bad_cast& e2) {    // compiler warns such mistake, even flag as error
    // ... handle dynamic_cast failure ...
  //}
}

int main() {
  f_catch_exceptions_in_appropriate_order();
}
