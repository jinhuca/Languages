// C140200_namespaces.cpp 
#include <iostream>
#include "Graph_lib.h"
#include "Text_lib.h"

void f() {
  Graph_lib::Text t1{};
  Text_lib::Text t2{};
}

int main() {
  f();
}
