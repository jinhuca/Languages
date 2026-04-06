// C200200_derived_classes.cpp 
#include <iostream>
#include "Employee.h"

void f(Manager m1, Employee e1) {
  std::list<Employee*> elist{&m1, &e1};
}

void g(Manager mm, Employee ee) {
  Employee* pe = &mm;                 // OK: every Manager is an Employee
  // Manager* pm = &ee;               // error: not every Employee is a Manager

  Manager* pm = &mm;
  pm->level = 2;                      // disaster: ee doesn't have a level
  pm = static_cast<Manager*>(pe);     // brute force: works because pe points
                                      // to the Manager mm
  pm->level = 2;                      // fine: pm points to the Manager mm that has a level
}

int main() {}
