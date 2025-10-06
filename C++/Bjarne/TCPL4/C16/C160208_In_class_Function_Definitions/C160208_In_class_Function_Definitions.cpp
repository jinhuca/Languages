// C160208_In_class_Function_Definitions.cpp
import std;

class Date {
public:
  Date(int dd, int mm, int yy) : d(dd), m(mm), y(yy) {}
  int day() const { return d; }
  int month() const { return m; }
  int year() const { return y; }
  void add_month(int n);
private:
  int d, m, y;
};

inline void Date::add_month(int n) {   // add n months
  m += n;    // increment the Date's m
}

int main() {
  Date today(25, 6, 2024);
  std::cout << "Today is " << today.day() << "/" << today.month() << "/" << today.year() << "\n";
  today.add_month(1);  // add one month to today's date
  std::cout << "One month later it will be " << today.day() << "/" << today.month() << "/" << today.year() << "\n";
}
