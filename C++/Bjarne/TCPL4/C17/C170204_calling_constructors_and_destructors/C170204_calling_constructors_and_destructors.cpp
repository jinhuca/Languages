// C170204_calling_constructors_and_destructors.cpp 
#include <iostream>

class Nonlocal {
public:
  // ...
  void destroy() { delete this; }           // explicit destruction
private:
  // ...
  ~Nonlocal() { std::cout << "dtor.\n"; }   // don't allow implicit destruction
};

int main() {
  Nonlocal x;                   // error: destructor is private
  Nonlocal* p = new Nonlocal;   // OK: constructor is public
  // ...
  delete p;                     // error: destructor is private
  p->destroy();                 // OK: explicit destruction
}
