// C0302_Usage.cpp 
#include <iostream>

class MyClass {
  inline static std::string msg{ "OK" };  // OK since C++17
};

int main() {
  std::cout << "Hello World!\n";
}
