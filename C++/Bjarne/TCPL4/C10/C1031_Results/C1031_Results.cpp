// C1031_Results.cpp 
import std;

void f(int x, int y) {
  int j = x = y;                  // the value of x=y is the value of x after the assignment with y
  int* p = &++x;                  // p points to x
  // int* q = &(x++);             // error: x++ is not an lvalue (it is not the value stored in x)
  int* p2 = &(x > y ? x : y);     // address of the int with the large value
  // int& r = (x < y) ? x : 1;    // error: 1 is not an lvalue
}

void g() {
  int i = 1;
  while(i > 0) ++i;
  std::cout << "i has become negative! " << i << '\n';
}

int main() {
  //int a = 1;
  //int b = 3;
  //f(a, b);
  g();
}
