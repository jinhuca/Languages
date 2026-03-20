// C130400_enforcing_invariants.cpp 
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

using std::string;
using std::runtime_error;
using std::ostringstream;

constexpr int CURRENT_MODE = 0;
constexpr int CURRENT_LEVEL = 0;

namespace Assert {
  enum class Mode { throw_, terminate_, ignore_ };

  constexpr Mode current_mode = static_cast<Mode>(CURRENT_MODE);
  constexpr int current_level = CURRENT_LEVEL;

  constexpr int default_level = 1;

  constexpr bool level(int n) { return n <= current_level; }
  struct Error : runtime_error {
    Error(const string& p) : runtime_error(p) {}
  };

  string compose(const char* file, int line, const string& message) {
    ostringstream oss{"("};
    oss << file << ", " << file << "):" << message;
    return oss.str();
  }
}

int main() {
  std::cout << "Hello World!\n";
}
