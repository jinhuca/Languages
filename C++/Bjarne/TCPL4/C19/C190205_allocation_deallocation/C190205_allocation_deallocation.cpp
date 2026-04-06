// C190205_allocation_deallocation.cpp 
#include <iostream>

class Employee {
public:
  void* operator new(size_t);
  void operator delete(void*, size_t);

  void* operator new[](size_t);
  void operator delete[](void*, size_t);
};

void* Employee::operator new(size_t s) {
  // allocate s bytes of memory and return a pointer to it
  return nullptr;
}

void Employee::operator delete(void* p, size_t s) {
  if(p) {   // delete only if p!=0;
    // assume p points to s bytes of memory allocated by Employee::operator new()
    // and free that memory for reuse
  }
}

void* Employee::operator new[](size_t) {
  return nullptr;
}

void Employee::operator delete[](void*, size_t) {
}

int main() {
}
