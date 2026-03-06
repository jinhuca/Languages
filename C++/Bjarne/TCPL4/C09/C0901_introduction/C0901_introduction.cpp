// C0901_introduction.cpp: statements are used to specify the order of execution of the program. 
// A statement is a complete instruction that performs some action. 
// In C++, statements are typically terminated with a semicolon (;). 
// The main function is the entry point of a C++ program, and it contains the statements that define the program's behavior.

#include <iostream>

int main() {
  int a {1}, b {2}, c {3};
  a = b + c;
  if(a == 7)
    b = 10;
  else
    b = 11;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;
}
