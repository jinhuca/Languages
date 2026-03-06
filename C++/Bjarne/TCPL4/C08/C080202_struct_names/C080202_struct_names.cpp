// C080202_struct_names.cpp 
#include <iostream>
struct List;    // forward declaration: List to be defined later

struct Link {
  Link* previous;
  Link* successor;
  List* member_of;
  int data;
};

struct No_good {
  // recursive definition of 'No_good'
  // No_good member;     // error: member has incomplete type 'No_good'
};

struct List {
  Link* head;
};

struct S;         // "S" is the name of some type

extern S a;
S construct_struct_with_default_constructor();            // "f" is the name of some function that returns an "S"
void g(S);        // "g" is the name of some function that takes an "S" as parameter
S* h(S*);         // "h" is the name of some function that takes a pointer to an "S" and returns a pointer to an "S"

void k(S* p) {
  // S a;             // error: 'S' has incomplete type - 'S' is not defined yet

  // f();             // error: 'f' has incomplete return type - 'S' is not defined yet
  // g(a);            // error: 'a' has incomplete type - 'S' is not defined yet
  // p->member = 7;   // error: 'S' has incomplete type - 'S' is not defined yet

  // S* q = h(p);     // error: 'h' has incomplete return type - 'S' is not defined yet
  // q->member = 8;   // error: 'S' has incomplete type - 'S' is not defined yet
}

struct stats { /*...*/ };
// int stat(const char* path, struct stat* buf);

int main() {
  std::cout << "Hello World!\n";
}
