// C16291_Constant_Member_Functions.cpp 
import std;

class Date {
  int d, m, y;
public:
  Date(int dd, int mm, int yy) : d {dd}, m {mm}, y {yy} {}
  int day() const { return d; }
  int month() const { return m; }
  int year() const;

  void add_year(int n) { y += n; }
};

int Date::year() const {    // const keyword required in definition outside of class
  return y;
}

void f(Date& d, const Date& cd) {
  int i = d.year();
  d.add_year(1);

  int j = cd.year();
  //cd.add_year(1);   // error
}

int main() {
  Date d {1, 2, 1978};
  std::cout << d.day() << '/' << d.month() << '/' << d.year() << '\n';
  Date cd {11, 21, 1981};
  std::cout << cd.day() << '/' << cd.month() << '/' << cd.year() << '\n';
  f(d, cd);
  std::cout << d.day() << '/' << d.month() << '/' << d.year() << '\n';
  std::cout << cd.day() << '/' << cd.month() << '/' << cd.year() << '\n';
}
