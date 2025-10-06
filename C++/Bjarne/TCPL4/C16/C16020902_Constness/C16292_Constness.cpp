// C16292_Constness.cpp 
import std;

class Date {
public:
  std::string string_rep() const;     // string representation
private:
  bool cache_valid;
  std::string cache;
  void compute_cache_value();         // fill cache
};

int main() {

}
