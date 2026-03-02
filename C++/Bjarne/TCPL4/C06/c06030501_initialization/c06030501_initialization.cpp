// c06030501_initialization.cpp 
#include <iostream>
#include <string>
#include <vector>

void f() {
  int x;                                     // x does not have a well-defined value until it is initialized.
  char buf[1024];                            // buf does not have a well-defined value until it is initialized.

  int* p {new int};                     // *p does not have a well-defined value until it is initialized.
  char* q {new char[1024]};             // *q does not have a well-defined value until it is initialized.

  std::string s;                        // s is initialized to an empty string because of string's default constructor.
  std::vector<char> v;                  // v is initialized to an empty vector because of vector's default constructor.

  std::string* ps {new std::string};    // *ps is initialized to an empty string because of string's default constructor.
}

void ff() {
  int x {};                            // x is initialized to 0 because of value initialization.
  char buf[1024] {};                   // each element of buf is initialized to '\0' because of value initialization.

  int* p {new int{10}};                // *p is initialized to 10 because of value initialization.
  char* q {new char[ 1024 ] {}};       // each element of *q is initialized to '\0' because of value initialization.
}

int main() {
  f();
  ff();
}
