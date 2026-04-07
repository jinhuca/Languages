// C200303_explicit_qualification.cpp 
#include <iostream>
#include <string>
#include <list>

using std::string;
using std::list;
using std::cout;

class Employee {
public:
  Employee(const string& name, short dept);
  virtual void print() const;
  // ...
private:
  string first_name, family_name;
  short department;
  // ...
};

Employee::Employee(const string& n, short d)
  :family_name{n}, department{d} {
}

void Employee::print() const {
  cout << family_name << '\t' << first_name << '\n';
}

class Manager :public Employee {
public:
  Manager(const string& name, short dept, short lvl);
  void print() const;
  // ...
private:
  list<Employee*> group;
  short level;
  // ...
};

Manager::Manager(const string& n, short d, short lvl)
  : Employee(n, d), level{lvl} {
}

void Manager::print() const {
  Employee::print();
  cout << "\tlevel " << level << '\n';
  // ...
}

void print_list(list<Employee*>& s) {
  for(const auto& e : s)
    e->print();
}

int main() {
  Employee e1{"Brown", 1234};
  Manager m1{"Smith", 1234, 2};
  auto lst = list<Employee*>{&m1, &e1};
  print_list(lst);
}
