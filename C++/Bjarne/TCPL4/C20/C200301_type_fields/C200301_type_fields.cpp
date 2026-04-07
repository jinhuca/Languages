// C200301_type_fields.cpp 
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;

struct Date {};

struct Employee {
  enum Empl_type { man, empl };
  Empl_type type;

  Employee() :type{empl} {}
  string first_name, family_name;
  char middle_initial;

  Date hiring_date;
  short department;
  // ...
};

struct Manager :public Employee {
  Manager() { type = man; }

  list<Employee*> group;
  short level;
  // ...
};

void print_employee(const Employee* e) {
  switch(e->type) {
  case Employee::empl:
    cout << e->family_name << '\t' << e->department << '\n';
    // ...
    break;
  case Employee::man:
    cout << e->family_name << '\t' << e->department << '\n';
    // ...
    const Manager* p = static_cast<const Manager*>(e);
    cout << "level " << p->level << '\n';
    // ...
    break;
  }
}

void print_list(const list<Employee*>& elist) {
  for(const auto x : elist)
    print_employee(x);
}

int main() {

}
