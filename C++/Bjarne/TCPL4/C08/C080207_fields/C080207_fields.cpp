// C080207_fields.cpp 
#include <iostream>

struct PPN {      // R6000 Physical Page Number
  unsigned int PFN : 22;      // page frame number
  int : 3;                    // unused
  unsigned int CCA : 3;       // cache coherency attribute
  bool nonreachable : 1;      // page is not reachable
  bool dirty : 1;             // page has been written to
  bool valid : 1;             // page is valid
  bool global : 1;            // page is global
};

void part_of_VM_system(PPN* p) {
  if(p->dirty) {  // contents changed
    // copy to disk
    p->dirty = 0;             // mark as clean
  }
}

void size_of_struct() {
  std::cout << "sizeof(PPN) = " << sizeof(PPN) << "\n";
}

int main() {
  size_of_struct();
}
