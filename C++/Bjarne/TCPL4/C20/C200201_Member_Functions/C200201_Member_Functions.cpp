// C200201_member_functions.cpp 
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Employee {
public:
  void print() const {};
  string full_name() const {
    return first_name + ' ' + middle_initial + ' ' + family_name;
  }
private:
  string first_name, family_name;
  char middle_initial;
  // ...
};

class Manager :public Employee {
  int level;
public:
  void print() const;
};

void Manager::print() const {
  Employee::print();      // (1) call base member function.
  cout << level;          // (2) do what the derived-specific action.
  // cout << "family name is " << family_name << '\n';   // error: can't access base's private from derived
}

int main() {}
