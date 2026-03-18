// C130102_traditional_error_handling.cpp
#include <iostream>

/* Method 1: terminate the program
*  This is not general approach to handle error when performing task,
*  User encounters termination, i.e., program crash.
*/
void terminate_if_error(int x) {
  if(x < 0 || x > 100) {
    std::cout << "task1 can't continue, given the out-of-range value.\n";
    exit(1);
  }
  std::cout << "task1 finished sucessfully.\n";
}

/* Method 2: return an error code
*  This is very limited approach, e.g., some functions have no return value.
*  There is no generally-accepted error code.
*/
int ERROR_CODE_1 = 101;
int ERROR_CODE_2 = 102;
int get_int() {
  int value;
  std::cout << "enter an integer: ";
  std::cin >> value;
  if(value > 0 || value < 10) return value;
  if(value < 0) return ERROR_CODE_1;
  if(value > 10) return ERROR_CODE_2;
}

/* Method 3: return a legal value and leave the program in an "error state"
*/
double get_sqrt(double d) {
  if(d < 0) {
    errno = 13;     // (1) set error number globally to indicate error happens.
    return 1;       // (2) return a legal value, but it is meaningless.
  }
  return sqrt(d);
}

/* Method 4: call an error-handler function
*/
void helper(const char* msg) {
  std::cerr << msg << '\n';   // can't handle properly.....
}

void call_another_function(int x) {
  if(x > 100) helper("error happens");
}

int main() {
  //terminate_if_error(5);
  //auto result = get_int();
  //std::cout << result << '\n';
  std::cout << get_sqrt(-1.2) << '\n';
}
