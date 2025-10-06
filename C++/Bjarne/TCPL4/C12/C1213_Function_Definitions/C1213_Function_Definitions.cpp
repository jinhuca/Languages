// C1213_Function_Definitions.cpp 
import std;

void swap(int*, int*);        // a function declaration

void swap(int* p, int* q) {   // a function definition
  int t = *p;
  *p = *q;
  *q = t;
}

int& max(int& a, int& b, int& c);     // return a reference to the larger of a, b, and c

int& max(int& x1, int& x2, int& x3) {
  return (x1 > x2) ? ((x1 > x3) ? x1 : x3) : ((x2 > x3) ? x2 : x3);
}

void f(int x) {
  std::cout << x << '\n';
}

//void f(const int x) {         // the same as "void f(int x)", can't have this definition. 
//  std::cout << x << '\n';
//}

void search(int* t, const char* key, const char*) {
  std::cout << "call function with unused parameter.\n";
}

int main() {
  int x = 1;
  int y = 2;
  int* p = &x;
  int* q = &y;
  std::cout << "*p = " << *p << '\t' << "*q = " << *q << '\n';
  swap(p, q);
  std::cout << "*p = " << *p << '\t' << "*q = " << *q << '\n';

  int x1 = 31, x2 = 12, x3 = 53;
  std::cout << "max of " << x1 << ", " << x2 << ", " << x3 << " is " << max(x1, x2, x3);

  char ca[] = "hello";
  search(p, ca, ca);
}
