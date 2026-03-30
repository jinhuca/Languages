// C160200_class_basics.cpp 
#include <iostream>

class X {
private:                      // the representation (implementation) is private
  int m;
public:                       // the interface is public
  X(int i = 0) : m{i} {}      // a constructor (initialize the data member m)
  int mf(int i) {             // a member function
    int old = m;
    m = i;                    // set a new value
    return old;               // return the old value
  }
};

X var{7};                     // a global variable of type X, initialized with 7

void user(X var, X* ptr) {
  int x = var.mf(7);          // access using . (dot) operator
  int y = ptr->mf(9);         // access using -> (arrow) operator
  // int z = var.m;              // error: m is private, cannot be accessed from outside the class
}

int main() {
  X x1{3};                    // create an object of type X, initialized with 3
  X x2{5};                    // create another object of type X, initialized with 5
  X* p1 = &x2;                // create a pointer to x2
  user(x1, p1);               // call the user function with x1 and a pointer to x2
}
