// C13050205_termination.cpp
#include <iostream>

using terminate_handler = void(*)();      // from <exception>

[[noreturn]] void my_handler() {          // a terminate handler cannot return
  // handle termination my way
}

void dangerous() {      // very!
  terminate_handler old = std::set_terminate(my_handler);
  // ...
  set_terminate(old);   // restore the old terminate handler
}

struct My_error{};

int main()
try {
  // ...
}
catch(const My_error& err1) {
  // ...
}
catch(const std::range_error& err2) {
  std::cerr << "range error: Not again!\n";
}
catch(const std::bad_alloc&) {
  std::cerr << "new ran out of memory\n";
}
catch(...) {
  // ...
}