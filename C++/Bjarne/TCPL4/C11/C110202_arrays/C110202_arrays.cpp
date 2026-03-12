// C110202_arrays.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

char* save_string(const char* p) {
  char* s = new char[strlen(p) + 1];
  strcpy(s, p);
  return s;
}

int main(int argc, char* argv[]) {
  std::cout << "No. of main arguments = " << argc << '\n';
  for(int i = 0; i != argc; i++)
    std::cout << argv[i] << ' ';

  if(argc < 2) exit(1);
  char* p = save_string(argv[1]);
  // ...
  delete[] p;
}
