#pragma once
#include <list>
#include <string>
#include "Date.h"

struct Employee {
  std::string first_name, family_name;
  char middle_initial;
  Date hiring_data;
  short department;
  // ...
};

struct Manager : public Employee {
  std::list<Employee> group;    // people managed
  short level;
  // ...
};
