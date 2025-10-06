// C2002_Derived_Classes.cpp 
import std;

struct Date {

};

struct Employee {
  std::string first_name, family_name;
  char middle_initial;
  Date hiring_date;
  short department;
  // ...
};

struct Manager : Employee {
  std::list<Employee> group;
  short level;
  // ...
};

void f(Manager m1, Employee e1) {
  std::list<Employee*> elist { &m1, &e1 };
}

void g(Manager mm, Employee ee) {
  Employee* pe = &mm;     // OK: every Manager is an Employee
  Manager* pm = &ee;      // error: not every Employee is a Manager

  pm->level = 2;          // disaster: ee doesn't have a level
  pm = static_cast<Manager>(pe);    // brute force: works because pe points to the Manager mm
  pm->level = 2;          // fine: pm points to the Manager mm that has a level
}

int main() {
  Employee e1 { "Jon" };
  Manager m1 { "Doe" };
  f(m1, e1);
}