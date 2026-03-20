// C130400_enforcing_invariants.cpp 
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

using std::string;
using std::runtime_error;
using std::ostringstream;
using std::exception;

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
    ostringstream oss {"("};
    oss << file << ", " << file << "):" << message;
    return oss.str();
  }

  template<bool condition = level(default_level), typename Except = Error>
  void dynamic(bool assertion, const string& message = "Assert::dynamic failed") {
    if(assertion)
      return;
    if(current_mode == Mode::throw_)
      throw exception(message.c_str());
    if(current_mode == Mode::terminate_)
      std::terminate();
  }

  template<>
  void dynamic<false, Error>(bool, const string&) {   // do nothing
  }

  void dynamic(bool b, const string& s) {   // default action
    dynamic<true, Error>(b, s);
  }

  void dynamic(bool b) {      // default message
    dynamic<true, Error>(b);
  }
}

constexpr int max = 1024;
void f(int n) {   // n should be in [1:max)
  Assert::dynamic<Assert::level(1), Assert::Error>(
    (1 <= n && n < max),
    Assert::compose(__FILE__, __LINE__, "range problem"));
}

void g(int n) {
  Assert::dynamic((1 <= n && n < max),
    Assert::compose(__FILE__, __LINE__, "range problem"));
}

void h(int n) {
  Assert::dynamic(1 <= n && n < max);
}

int main() {
  //f(2001);
  //g(2002);
  h(1003);
}
