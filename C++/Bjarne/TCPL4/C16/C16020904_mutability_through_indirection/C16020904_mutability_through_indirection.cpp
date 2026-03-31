// C16020904_mutability_through_indirection.cpp 
#include <string>
using namespace std;

struct cache {
  bool valid;
  string rep;
};

class Date {
public:
  //...
  string string_rep() const;            // string representation
private:
  cache* c;                             // initialize in constructor
  void compute_cache_value() const;     // fill what cache refers to
};

string Date::string_rep() const {
  if(!c->valid) {
    compute_cache_value();
    c->valid = true;
  }
  return c->rep;
}

void Date::compute_cache_value() const {
  // compute the string representation of the date and store it in c->rep
}
int main() {
}
