// C110202_strings.cpp 
#include <iostream>
#include <string>

std::string save_string(const char* p) {
  return std::string(p);
}

int main(int argc, char* argv[]) {
  if(argc < 2) exit(1);
  std::string s = save_string(argv[1]);
  std::cout << "first argument to main is: " << s << '\n';
}
