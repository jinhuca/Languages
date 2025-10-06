// C072_Pointers.cpp 
import std;

void f() {
  char c = 'a';     // c is a variable of type char with value 'a'
  char* p = &c;     // p holds the address of c; & is the address-of operator
  char c2 = *p;     // c2 = 'a'; * is the dereference operator
}

void g() {
  int* pi;            // pointer to int
  char** ppc;         // pointer to pointer to char
  int* ap[15];        // array of 15 pointers to int
  int (*fp)(char*);   // pointer to function, which takes a char* argument; returns an int
  int* f(char*);      // function taking a char* argument; returns a pointer to int
}

int main() {
  f(); 
}
