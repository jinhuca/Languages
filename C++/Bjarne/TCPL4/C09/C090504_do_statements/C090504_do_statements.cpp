// C090504_do_statements.cpp 
#include <iostream>

void print_backwards(char a[], int i) {   // i must be positive
  std::cout << '{';
  do {
    std::cout << a[--i];
  } while(i);
  std::cout << "}\n";
}

int main() {
  char a[] { 'h', 'e', 'l', 'l', 'o' };
  print_backwards(a, 5);
}
