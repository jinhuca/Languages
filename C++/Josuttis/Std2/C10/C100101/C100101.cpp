// C100101.cpp 
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

class Person {
private:
  std::string fn;    // first name
  std::string ln;    // last name
public:
  Person() {
  }
  Person(const std::string& f, const std::string& n)
    : fn(f), ln(n) {
  }
  std::string firstname() const { return fn; }
  std::string lastname() const { return ln; }
  // ...
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
  return os << '[' << p.firstname() << " " << p.lastname() << ']';
}

/* binary function - predicate:
 * - returns whether a person is less than another person
 */
bool personSortCriterion(const Person& p1, const Person& p2) {
  /* a person is less than another person
   * - if the last name is less
   * - if the last name is equal and the first name is less
   */
  return p1.lastname() < p2.lastname() ||
    (p1.lastname() == p2.lastname() &&
      p1.firstname() < p2.firstname());
}

int main() {
  // create some persons
  Person p1("nicolai", "josuttis");
  Person p2("ulli", "josuttis");
  Person p3("anica", "josuttis");
  Person p4("lucas", "josuttis");
  Person p5("lucas", "otto");
  Person p6("lucas", "arm");
  Person p7("anica", "holle");

  // insert person into collection coll
  std::deque<Person> coll;
  coll.push_back(p1);
  coll.push_back(p2);
  coll.push_back(p3);
  coll.push_back(p4);
  coll.push_back(p5);
  coll.push_back(p6);
  coll.push_back(p7);

  // print elements
  std::cout << "deque before sort():" << '\n';
  std::deque<Person>::iterator pos;
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    std::cout << *pos << '\n';
  }

  // sort elements
  std::sort(coll.begin(), coll.end(),    // range
    personSortCriterion);       // sort criterion

  // print elements
  std::cout << "deque after sort():" << '\n';
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    std::cout << *pos << '\n';
  }
}