// C080201_struct_layout.cpp 
#include <iostream>

struct Readout1 {
  char hour;    // [0:23]
  int value;    // some value read at that hour
  char seq;     // sequence mark ['a':'z']
};

Readout1 r1 = { 12, 1234, 'a' };

void struct_layout1_test() {
  Readout1 r2 = { 12, 1234, 'a' };
  std::cout << "sizeof(Readout) = " << sizeof(Readout1) << "\n\n";
  std::cout << "sizeof(r2) = " << sizeof(r2) << "\n\n";

  std::cout << "address of r2: " << &r2 << '\n';
  std::cout << "addresses of r2 members: \n";
  std::cout << &(r2.hour) << '\n' << &(r2.value) << '\n' << &(r2.seq) << '\n';
}

struct Readout2 {
  int value;    // some value read at that hour
  char hour;    // [0:23]
  char seq;     // sequence mark ['a':'z']
};

struct no_member_struct {
};

void struct_layout2_test() {
  Readout2 r2 = { 1234, 12, 'a' };
  std::cout << "sizeof(Readout) = " << sizeof(Readout2) << "\n\n";
  std::cout << "sizeof(r2) = " << sizeof(r2) << "\n\n";
  std::cout << "address of r2: " << &r2 << '\n';
  std::cout << "addresses of r2 members: \n";
  std::cout << &(r2.value) << '\n' << &(r2.hour) << '\n' << &(r2.seq) << '\n';
}

size_t get_struct_size() {
  return sizeof(Readout1);
}

size_t get_array_of_struct_size() {
  return sizeof(Readout1[10]);
}

void struct_size_test() {
  std::cout << "sizeof(Readout1) = " << sizeof(Readout1) << "\n";
  std::cout << "sizeof(Readout2) = " << sizeof(Readout2) << "\n";
  
  std::cout << "size of Readout1[10] = " << sizeof(Readout1[10]) << "\n";
  std::cout << "size of array of Readout1 = " << get_array_of_struct_size() << '\n';

  std::cout << "size of no_member_struct = " << sizeof(no_member_struct) << "\n";
}

int main() {
  struct_layout1_test();
  struct_layout2_test();
  struct_size_test();
}
