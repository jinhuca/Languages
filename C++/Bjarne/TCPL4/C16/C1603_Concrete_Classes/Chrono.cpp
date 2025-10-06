import std;
import Chrono;

using Date = Chrono::Date;
using Month = Chrono::Month;

Date::Date(int dd, Month mm, int yy)
  : d { dd }, m { mm }, y { yy } {
  if(y == 0) y = default_date().year();
  if(m == Month {}) m = default_date().month();
  if(d == 0) d = default_date().day();
  if(!is_valid()) throw Bad_date();
}

inline int Date::day() const { return d; }
inline Month Date::month() const { return m; }
inline int Date::year() const { return y; }

std::string Date::string_rep() const {
  std::string month = "";
  switch(m) {
  case Month::jan:
    month = "January";
    break;
  case Month::feb:
    month = "February";
    break;
  case Month::mar:
    month = "March";
    break;
  case Month::apr:
    month = "April";
    break;
  case Month::may:
    month = "May";
    break;
  case Month::jun:
    month = "June";
    break;
  case Month::jul:
    month = "July";
    break;
  case Month::aug:
    month = "August";
    break;
  case Month::sep:
    month = "September";
    break;
  case Month::oct:
    month = "October";
    break;
  case Month::nov:
    month = "November";
    break;
  case Month::dec:
    month = "December";
    break;
  }
  std::string result = "Year: " + std::to_string(y) + " month: " + month + " day: " + std::to_string(d);
  return result;
}

void Date::char_rep(char s[], int max) const {
}

Date& Date::add_day(int n) {
  d += n;
  return *this;
}

Date& Date::add_year(int n) {
  if(d == 29 && m == Month::feb && !is_leapyear(y + n)) {
    d = 1;
    m = Month::mar;
  }
  y += n;
  return *this;
}

Date& Date::add_month(int n) {
  if(n == 0) return *this;
  if(n > 0) {
    int delta_y = n / 12;                     // number of whole years
    int mm = static_cast<int>(m) + n % 12;    // number of months ahead
    if(12 < mm) {
      ++delta_y;
      mm -= 12;
    }
    // ... handle the cases where the month mm doesn't have day d ...
    y += delta_y;
    m = static_cast<Month>(mm);
    return *this;
  }
  // ... handle negative n ...
  return *this;
}


bool Date::is_valid() {
  return is_date(d, m, y);
}

bool Chrono::is_date(int d, Month m, int y) {
  return (d > 0 && d < 31) && (m >= Month::jan && m <= Month::dec);
}

bool Chrono::is_leapyear(int y) {
  return y % 4 == 0;
}

bool Chrono::operator==(Date a, Date b) {
  return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

bool Chrono::operator!=(Date a, Date b) {
  return !(a == b);
}

const Date& Chrono::default_date() {
  return Date { 1,Month::jan,1969 };
}

std::ostream& Chrono::operator<<(std::ostream& os, const Date& d) {
  os << d.string_rep();
  return os;
}

std::istream& Chrono::operator>>(std::istream& is, Date& d) {
  int dd, mm, yy;
  is >> dd >> mm >> yy;
  Month mi;
  mi = static_cast<Month>(mm);
  d = Date { dd, mi,yy };
  return is;
}