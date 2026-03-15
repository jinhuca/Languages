// C120103_function_definitions.cpp 
#include <iostream>
#include <string>

void swap(int*, int*);          // a function declaration

void swap(int* p, int* q) {     // a function definition
  int t = *p;
  *p = *q;
  *q = t;
}

//void f(int x) {                   // type is void(int)
//  /* we can modify x here */
//}

void f(const int x) {               // type is void(int)
  /* we cannot modify x here */ 
}

// function argument names are not part of the function type
int& max(int& a, int& b, int& c);   // return a reference to the larger of a, b, and c

int& max(int& x1, int& x2, int& x3) {
  return (x1>x2) ? ((x1>x3) ? x1 : x3) : ((x2>x3) ? x2 : x3);
}

int& call_max(int& x, int& y, int& z) {
  return max(x, y, z);
}

void demo_max() {
  int a = 1, b = 21, c = -12;
  std::cout<<max(a, b, c)<<'\n';
}

void search(std::string* t, const char* key, const char*) {
  // no use of the third argument
}

int main() {
  demo_max();
}
