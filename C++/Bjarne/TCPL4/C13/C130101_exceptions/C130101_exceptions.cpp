// C130101_exceptions.cpp 
#include <iostream>

struct Some_error {};

int do_task(int x) {
  // ...
  if(x < 10) { /* could perform the task */
    auto result = x * 2;
    std::cout << "sucessfully finished at " << result << ".\n";
    return result;
  }
  else
    throw Some_error{};
}

void taskmaster(int load) {
  try {
    auto result = do_task(load);
    // use result
  }
  catch(Some_error) {
    // failure to do_task: handle problem
    std::cerr << "some error happened when do_task.\n";
  }
}

int main() {
  int load1 = 5;
  int load2 = 21;
  taskmaster(load1);
  taskmaster(load2);
}
