// P0476.cpp: function object as sorting criteria
import std;

class Person {
private:
  std::string fn;   // first name
  std::string ln;   // last name
public:
  Person() {}
  Person(const std::string& f, const std::string& n) : fn(f), ln(n) {
  }
  std::string firstname() const;
  std::string lastname() const;
};

inline std::string Person::firstname() const {
  return fn;
}

inline std::string Person::lastname() const {
  return ln;
}

std::ostream& operator<<(std::ostream& s, const Person& p) {
  s << "[" << p.firstname() << " " << p.lastname() << "]";
  return s;
}

/* class for function predicate
 * - operator() returns whether a person is less than another person
 */
class PersonSortCriterion {
public:
  bool operator()(const Person& p1, const Person& p2) const {
    return p1.lastname() < p2.lastname() 
      || (p1.lastname() == p2.lastname() && p1.firstname() < p2.firstname());
  }
};

int main()
{
  Person p1("nicolai", "josuttis");
  Person p2("ulli", "josuttis");
  Person p3("anica", "josuttis");
  Person p4("lucas", "josuttis");
  Person p5("lucas", "otto");
  Person p6("lucas", "arm");
  Person p7("anica", "holle");

  // declare set type with special sorting criterion
  typedef std::set<Person, PersonSortCriterion> PersonSet;

  PersonSet coll;
  coll.insert(p1);
  coll.insert(p2);
  coll.insert(p3);
  coll.insert(p4);
  coll.insert(p5);
  coll.insert(p6);
  coll.insert(p7);

  std::cout << "set:" << std::endl;
  PersonSet::iterator pos;
  for (pos = coll.begin(); pos != coll.end(); ++pos) {
    std::cout << *pos << std::endl;
  }
}
