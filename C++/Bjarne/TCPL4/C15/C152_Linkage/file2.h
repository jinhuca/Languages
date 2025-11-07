// file2.h
#pragma once
#include <iostream>
#include "file1.h"

extern int x;
int f();
void g() {
  x = f();
  std::cout << "g() in file2.\n";
}