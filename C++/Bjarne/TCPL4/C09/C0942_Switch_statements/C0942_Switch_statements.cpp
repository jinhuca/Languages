// C0942_Switch_statements.cpp 
import std;

void f(int i) {
  switch(i) {
  //case 2.7:   // error: floating-point uses for case
    //...
  case 2:
    // ...
    break;
  case 4:
    // ...
    break;
  //case 2:       // error: 2 used twice in case labels
    break;
  }
}

void g(int i) {
  switch(i) {
  case 0:
    int x;                // uninitialized
    //int y = 3;            // error: declaration can be bypassed (explicitly initialized)
    //std::string s;        // error: declaration can be bypassed (explicitly initialized)
    break;
  case 1:
    //++x;
    //++y;
    //s = "nasty";
    break;
  }
}
int main() {
  std::cout << "Hello World!\n";
}
