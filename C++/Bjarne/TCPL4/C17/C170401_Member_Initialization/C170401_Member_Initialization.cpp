// C170401_Member_Initialization.cpp 
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

Club::Club(const std::string& n, Date fd)
  : name { n }, members {}, officers {}, founded { fd } {
}

void f() {
  Club c1 { "Black Hawk", Date{ 1, 1, 1970 } };
}

int main() {
  f();
}
