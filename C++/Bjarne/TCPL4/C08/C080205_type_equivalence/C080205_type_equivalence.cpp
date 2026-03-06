// C080205_type_equivalence.cpp 
#include <iostream>

struct S1 { int a; };
struct S2 { int a; };

void test_structs_type_equivalence() {
  S1 s1 = { 1 };
  S2 s2 = { 1 };
  // s1 = s2;    // error: cannot assign 'S2' to 'S1' - different types
  // S1 s3 = s2; // error: cannot initialize 'S1' with 'S2' - different types
}

int main() {
  test_structs_type_equivalence();
}
