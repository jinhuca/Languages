#include "Date.h"

using namespace std;
using namespace Chrono;

Date::Date(int dd, Month mm, int yy)
  : d{dd}, m{static_cast<int>(mm)}, y{yy} {
  if(y == 0) y = default_date().year();    // use default year if yy == 0
  if(m == Month{}) m = default_date().month();  // use default month if mm == 0
  if(d == 0) d = default_date().day();    // use default day if dd == 0
  if(!is_valid()) throw Bad_date{};
}

int Chrono::Date::day() const {
  return d;
}

Month Chrono::Date::month() const {
  return m;
}

int Chrono::Date::year() const {
  return y;
}

Date& Chrono::Date::add_day(int n) {

  return *this;
}

Date& Chrono::Date::add_month(int n) {
  if(n == 0) return *this;
  if(n > 0) {
    int delta_y = n / 12;                   // number of whole years
    int mm = static_cast<int>(m) + n % 12;  // number of months ahead
    if(12 < mm) {                           // note: dec is represented by 12
      ++delta_y;
      mm -= 12;
    }
    // ... handle the case where the month mm doesn't have day d ...
    y += delta_y;
    m = static_cast<Month>(mm);
    return *this;
  }
  // ... handle the case where n < 0 ...
  return *this;
}

Date& Chrono::Date::add_year(int n) {
  y += n;
  return *this;
}

inline bool operator==(Date a, Date b) {
  return a.day() == b.day()
    && a.month() == b.month()
    && a.year() == b.year();
}

bool Chrono::Date::is_valid() {
  return is_date(d, m, y);
}

bool Chrono::is_date(int d, Month m, int y) {
  int ndays;
  switch(m) {
  case Month::feb:
    ndays = (leapyear(y)) ? 29 : 28;
    break;
  case Month::apr: case Month::jun: case Month::sep: case Month::nov:
    ndays = 30;
    break;
  case Month::jan: case Month::mar: case Month::may: case Month::jul:
  case Month::aug: case Month::oct: case Month::dec:
    ndays = 31;
    break;
  default:
    return false;
  }
  return 1 <= d && d <= ndays;
}

const Date& default_date() {
  static Date d{1, Month::jan, 1970};
  return d;
}

bool Chrono::operator==(const Date& a, const Date& b) {
  return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}

bool Chrono::operator!=(const Date& a, const Date& b) {
  return !(a == b);
}
