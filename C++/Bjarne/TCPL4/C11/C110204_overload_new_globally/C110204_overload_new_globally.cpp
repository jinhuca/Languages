// C110204_overload_new.cpp 
#include <iostream>
#include <new>

void* operator new(std::size_t sz) {
  std::cout << "new(size_t), size = " << sz << '\n';
  if(sz == 0)
    ++sz;   // avoid std::malloc(0) which may return nullptr on success
  if(void* ptr = std::malloc(sz))
    return ptr;
  throw std::bad_alloc {};   // required
}

void operator delete(void* ptr) noexcept {
  std::cout << "delete(void*)\n";
  std::free(ptr);
}

void overload_new_in_global() {
  int* p1 = new int;
  delete p1;
  double* d1 = new double;
  delete d1;
}

class CustomMemory {
public:
  // Class-specific operator new
  static void* operator new(std::size_t size, void* p) {
    std::cout << "Custom new called for size: " << size << " bytes" << std::endl;
    void* ptr = std::malloc(size); // Delegate to standard C allocation
    if(!ptr) {
      throw std::bad_alloc(); // Handle allocation failure
    }
    return ptr;
  }

  // Class-specific operator delete
  static void operator delete(void* ptr) noexcept {
    std::cout << "Custom delete called" << std::endl;
    std::free(ptr); // Delegate to standard C deallocation
  }
};

void overload_new_in_class() {
  std::size_t sz = 1024;
  void* buf = reinterpret_cast<void*>(0xF00F);
  CustomMemory* obj = new(buf) CustomMemory;
  delete obj;
}

int main() {
  //overload_new_in_class();
  overload_new_in_global();
}
