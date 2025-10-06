// C16293_Mutable.cpp 
import std;

class Date {
public:
  std::string string_rep() const;     // string representation
private:
  mutable bool cache_valid;           // can be modified in const member function
  mutable std::string cache;
  void compute_cache_value() const;         // fill (mutable) cache
};

std::string Date::string_rep() const {
  if (!cache_valid) {
    compute_cache_value();
    cache_valid = true;
  }
  return cache;
}

void Date::compute_cache_value() const {}

void f(Date d, const Date& cd) {
  std::string s1 = d.string_rep();
  std::string s2 = cd.string_rep();
}

int main() {
}
