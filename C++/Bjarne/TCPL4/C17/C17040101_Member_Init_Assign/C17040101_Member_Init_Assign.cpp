// C17040101_Member_Init_Assign.cpp 
import std;

struct Date {
  int d, m, y;
};

class Club {
  int id;
  std::string name;
  std::vector<std::string> members;
  std::vector<std::string> officers;
  Date founded;
  // ...
public:
  Club(const std::string& n, Date fd);
};

class X {
  const  int i;
  Club cl;
  Club& rc;
  // ...
public:
  X(int ii, const std::string& n, Date d, Club& c)
    : i { ii }, cl { n, d }, rc { c } {
  }
};

class Person {
  std::string name;
  std::string address;
  // ...
public:
  Person(const Person&) {
  }

  Person(const std::string& n, const std::string& a) 
    : name { n } {
    address = a;
  }
};

int main() {
  
}
