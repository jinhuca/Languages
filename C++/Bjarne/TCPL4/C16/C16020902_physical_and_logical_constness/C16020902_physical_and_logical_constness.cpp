// C16020902_physical_and_logical_constness.cpp
#include <iostream>
#include <string>

class Date {
public:
  std::string string_rep() const { return std::to_string(d) + "/" + std::to_string(m) + "/" + std::to_string(y); }
private:
  bool cache_valid;
  std::string cache;
  void compute_cache() {
    cache = std::to_string(d) + "/" + std::to_string(m) + "/" + std::to_string(y);
    cache_valid = true;
  }
  int d, m, y;
};

int main() {
}
