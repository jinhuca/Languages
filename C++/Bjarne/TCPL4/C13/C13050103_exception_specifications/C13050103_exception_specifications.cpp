// C13050103_exception_specifications.cpp 
#include <iostream>

struct Bad {};
struct Worse {};

void f(int i) throw(Bad, Worse) {
}

void g(int i) throw() {
}

int main() {
  
}
