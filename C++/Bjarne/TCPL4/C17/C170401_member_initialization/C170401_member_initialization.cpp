// C170401_member_initialization.cpp 
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Date {
};

class Club {
  string name;
  vector<string> members;
  vector<string> officers;
  Date founded;
public:
  Club(const string& n, Date fd);
};

Club::Club(const string& n, Date fd)
  :name{n}, members{}, officers{}, founded{fd} {
  // ...
}

class X {
  const int i;
  Club cl;
  Club& rc;
  // ...
  X(int ii, const string& n, Date d, Club& c) :i{ii}, cl{n, d}, rc{c} {}
};

class Person {
  string name;
  string address;
public:
  Person(const Person&);
  Person(const string& n, const string& a);
};

Person::Person(const Person& other) 
  : name{other.name}, address{other.address} {
}

Person::Person(const string& n, const string& a)
  : name{n}       // use member initializer list
{
  address = a;    // use assignment to initialize
}

int main() {
}
