// C170301_initialization_without_constructors.cpp 
#include <iostream>
#include <string>
using std::string;

void initialize_built_in_types() {
  int i;                // uninitialized: i has an indeterminate value
  int a{1};             // initialized to 1 by the initializer
  double d{};           // initialized to 0.0 by the default initializer
  char c{'\0'};         // initialized to '\0' by the default initializer
  char* p{nullptr};     // initialized to nullptr by the default initializer
}

struct Work {
  string author;
  string name;
  int year;
};

Work s1;                // default initialization: members are initialized by their default constructors
                        // which is equivalent to Work s1{}; in this case

void initialize_with_memberwise_initialization() {
  Work s9{"Beethoven", "Symphony No. 9", 1824};   // memberwise initialization
  Work currently_playing{s9};   // copy initialization with s9
  Work none{};                  // default initialization: all members are initialized by their default constructors
}

struct Buf {
  int count;
  char buf[16*1024];
};

Buf buf0;                     // statically allocated, so initialized by default: 
                              // count is initialized to 0 and buf is initialized to all '\0' by the default initializer

void f() {
  Buf buf1;                   // local variable, so uninitialized: count has an indeterminate value and buf is uninitialized
  Buf buf2{};                 // I really want to zero out those elements of the local variable
  int* p1 = new int;          // dynamically allocated, so uninitialized: *p1 has an indeterminate value
  int* p2 = new int{};        // I really want to zero out that dynamically allocated int - *p2 == 0
  int* p3 = new int{7};       // *p3 == 7
}

template<typename T>
class Checked_pointer {       // control access to T* member
private:
  T* p;
public:
  T& operator*();             // check for nullptr and return value
};

Checked_pointer<int> p{new int{7}};   // error: can't acces p.p

int main() {
  initialize_built_in_types();
  initialize_with_memberwise_initialization();
}
