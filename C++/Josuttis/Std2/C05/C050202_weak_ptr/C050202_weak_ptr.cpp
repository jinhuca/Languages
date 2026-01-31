// C050202_weak_ptr.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Person {
public:
  string name;
  shared_ptr<Person> mom;
  shared_ptr<Person> dad;
  vector<weak_ptr<Person>> kids;

  Person(const string& n,
    shared_ptr<Person> m = nullptr,
    shared_ptr<Person> f = nullptr)
    : name(n), mom(m), dad(f) {
  }

  ~Person() {
    cout << "delete " << name << endl;
  }
};

shared_ptr<Person> initFamily(const string& name) {
  shared_ptr<Person> mom = make_shared<Person>(name + "'s Mother");
  shared_ptr<Person> dad = make_shared<Person>(name + "'s Father");
  shared_ptr<Person> kid(new Person(name, mom, dad));
  mom->kids.push_back(kid);
  dad->kids.push_back(kid);
  return kid;
}

int main() {
  shared_ptr<Person> p = initFamily("nico");
  cout << "nico's family exists.\n";
  cout << " - nico is shared " << p.use_count() << " times.\n";
  cout << " - name of 1st kid of nico's mom: " << p->mom->kids[0].lock()->name << "\n";
  
  p = initFamily("jim");
  cout << "jim's family exists.\n";
}
