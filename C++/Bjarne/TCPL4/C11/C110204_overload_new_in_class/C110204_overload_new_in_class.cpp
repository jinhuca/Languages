// C110204_overload_new_in_class.cpp 
#include <iostream>

class X_CustomMemory {
public:
  X_CustomMemory(int x) : data{x} {
    std::cout << "X_CustomMemory constructor called.\n";
  }
  ~X_CustomMemory() {
    std::cout << "X_CustomMemory destructor called.\n";
  }

  static void* operator new(size_t size, void* p) {   // size_t size is implicitly supplied
    std::cout << "custom new called for size: " << size << " bytes.\n";
    void* ptr = std::malloc(size);   // delegate to standard C allocation
    if(!ptr) {
      throw std::bad_alloc();       // handle allocation failure
    }
    return ptr;
  }
  
  static void operator delete(void* ptr) noexcept {
    std::cout << "custom delete called.\n";
    std::free(ptr);       // delegate to standard C deallocation
  }

private:
  int data;
};

int main() {
  void* buf = reinterpret_cast<void*>(0xF00F);
  X_CustomMemory* obj = new(buf) X_CustomMemory(99);
  delete obj;
}
