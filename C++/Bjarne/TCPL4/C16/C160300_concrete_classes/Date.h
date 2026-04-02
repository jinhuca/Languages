#pragma once
#include <string>

namespace Chrono {
  enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
  };

  class Date {
  public:
    class Bad_date {};                                        // exception class
    explicit Date(int dd = {}, Month mm = {}, int yy = {});   // {} means "pick a default"

    // non-modifying functions for examining the Date:
    int day() const;
    Month month() const;
    int year() const;
    
    std::string string_rep() const;           // string representation of the Date
    void char_rep(char s[], int max) const;   // C-style string representation

    // modifying functions for changing the Date:
    Date& add_day(int n);                     // add n days to this date
    Date& add_month(int n);                   // add n months to this date
    Date& add_year(int n);                    // add n years to this date

    Date operator+(int n);                    // add n days to this date
  private:
    bool is_valid();                          // check if this Date represents a valid date
    int d;                                    // day, month, year representation of a date
    Month m;
    int y;                              
  };

  // helper functions:
  int diff(Date a, Date b);                   // number of days in the range [a, b) or [b, a)
  bool leapyear(int y);                       // true if y is a leap year
  bool is_date(int d, Month m, int y);        // true for valid date
  
  const Date& default_date();                 // a default date
  Date next_weekday(Date d);
  Date next_saturday(Date d);

  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);
  bool operator<(const Date& a, const Date& b);
  bool operator>(const Date& a, const Date& b);
  
  std::ostream& operator<<(std::ostream& os, const Date& d);    // print d to os
  std::istream& operator>>(std::istream& is, Date& dd);         // read a Date from is into dd
} // Chrono