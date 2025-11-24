#include <iostream>

extern "C" int SomeFunction();

int main() {
  std::cout << "The result from asm proc is: " << SomeFunction() << std::endl;
  return 0;
}