// C0906_goto_statements.cpp 
#include <iostream>

int nm[10][10];

void do_something(int i, int j) {
  for(i = 0; i != 10; ++i) {
    for(j = 0; j != 10; ++j) {
      if(nm[i][j] == 11) goto found;
    }
  }
  // not found
  // ...
found:
  // nm[i][j] == a
  std::cout << "Found it!\n";
}

int main() {
  std::cout << "Hello World!\n";
}
