// C0402_HeaderFiles.cpp 
#include <iostream>
#include "myHeader.h"
#include "myAnotherHeader"

int main() {
  MyClass obj;
  obj.myFunction();

  MyAnotherClass anotherObj;
  anotherObj.anotherFunction();
}
