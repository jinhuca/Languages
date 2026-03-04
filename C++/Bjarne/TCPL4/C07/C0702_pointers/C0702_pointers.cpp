// C072_Pointers.cpp 
import std;

int demo(const char* p) {
  int length = 0;
  while(*p != '\0') { // loop until we reach the null terminator
    ++length; // increment length for each character
    ++p;      // move the pointer to the next character
  }
  return length;
}

void f() {
  char c = 'a';     // c is a variable of type char with value 'a'
  char* p = &c;     // p holds the address of c; & is the address-of operator
  char c2 = *p;     // c2 = 'a'; * is the dereference operator
}

void g() {
  int* pi;            // pointer to int
  char** ppc;         // pointer to pointer to char
  int* ap[15];        // array of 15 pointers to int
  int* f(char*);      // function taking a char* argument; returns a pointer to int
  int (*fp)(const char*) = demo;   // pointer to function, which takes a char* argument; returns an int
  std::cout << fp("Hello, C++") << '\n';      // call the function through the pointer; pass a char* argument
}

int main() {
  f();
  g();
}
