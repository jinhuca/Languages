// C110203_get_memory_space.cpp 
#include <iostream>
#include <vector>

// beware: this function try to allocate much memory to exhaust the physical and virtual memory.
void f() {     
  std::vector<char*> v;
  try {
    for(;;) {
      char* p = new char[10000];      // acquire some memory
      v.push_back(p);                 // make sure the new memory is referred
      p[0] = 'X';                     // use the new memory
    }
  }
  catch(std::bad_alloc) {
    std::cerr << "Memory exhausted!\n";
  }
}

int main() {
  f();
}
