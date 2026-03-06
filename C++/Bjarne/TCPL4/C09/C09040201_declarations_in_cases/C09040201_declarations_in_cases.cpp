// C09040201_declarations_in_cases.cpp 
#include <iostream>

void f(int i) {
  switch(i) {
  case 0:
    int x;                // uninitialized
    int y = 3;            // error: declaration can be bypassed (explicitly initialized)
    std::string s;        // error: declaration can be bypassed (explicitly initialized)
  case 1:
    ++x;                  // error: use of uninitialized variable 'x'
    ++y;                  // error: use of uninitialized variable 'y'
    s = "nasty!";
  }
}

int main() {
  f(4);
}
