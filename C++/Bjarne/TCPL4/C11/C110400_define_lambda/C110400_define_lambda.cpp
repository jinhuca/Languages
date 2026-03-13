// C110400_define_lambda.cpp 
#include <iostream>
#include <functional>

void function_accept_lambda(std::function<void(void)> func) {
  func();
}

void minimum_lambda() {
  auto minimin_lambda = []() {};                              // define a minimum lambda - which does nothing
                                                              // lambda has a unique, unnamed closure type 
                                                              // - which is compatible to std::function<void(void)>

  minimin_lambda();                                           // invoke it directly
  
  function_accept_lambda(minimin_lambda);                     // pass it as argument to function
}

void lambda_capture_variable() {
  int x = 1;                                                  // variable to be captured by lambda
  auto lambda_capture_variable = [x]() {
    std::cout << "captured variable = " << x << '\n';
  };
  lambda_capture_variable();
  function_accept_lambda(lambda_capture_variable);
}

void function_1(std::function<double(int)> f) {
  std::cout << f(10) << '\n';
}

void lambda_fully() {
  int y = 10;                                                 // variable to be captured by lambda
  auto lambda_1 = [&y](int i) mutable noexcept -> double {    // lambda which captures, has parameters, and returns value
    ++y;
    return static_cast<double>(y + i * 10);
  };
  lambda_1(12);                                               // invoke it directly
  function_1(lambda_1);                                       // pass it as argument to function
}

int main() {
  minimum_lambda();
  lambda_capture_variable();
}
