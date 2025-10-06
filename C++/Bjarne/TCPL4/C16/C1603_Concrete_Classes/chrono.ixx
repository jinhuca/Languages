export module Chrono;
import std;

export namespace Chrono {
  enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

  class Date {
  public:                                                     // public interface
    class Bad_date {};                                        // exception class
    explicit Date(int dd = {}, Month mm = {}, int yy = {});   // {} means "pick a default"

    // non-modifying functions for examining the Date:
    int day() const;
    Month month() const;
    int year() const;

    std::string string_rep() const;                           // string representation
    void char_rep(char s[], int max) const;                   // C-style string representation

    // modifying functions for changing the Date:
    Date& add_year(int n);                                    // add n years
    Date& add_month(int n);                                   // add n months
    Date& add_day(int n);                                     // add n days
  private:
    bool is_valid();                                          // check if this Date represents a date
    int d;                                                    // representation
    Month m;
    int y;
  };

  bool is_date(int d, Month m, int y);                        // true for valid date
  bool is_leapyear(int y);                                    // true if y is a leap year

  bool operator==(Date a, Date b);
  bool operator!=(Date a, Date b);

  const Date& default_date();                                 // the default date

  std::ostream& operator<<(std::ostream& os, const Date& d);  // print to os
  std::istream& operator>>(std::istream& is, Date& d);        // read Date from is into d
} // Chrono