// C1351_Throw_Exceptions.cpp 
import std;

class No_copy {
  No_copy(const No_copy&) = delete;     // prohibit copying
};

class My_error {
  // ...
public:
  My_error(int id) :errorMsg(std::to_string((id + 10))) {
    std::cout << "id for construction = " << id << '\n';
  };
  std::string errorMsg;
};

void f(int n) {
  switch(n) {
    case 0: throw My_error(0);     // OK
      //case 1: throw No_copy();    // error: can't copy a No_copy
      //case 2: throw My_error;     // error: My_error is a type, rather than an object
  }
}

void h() {
  std::string s = "not";
  throw My_error { 2 };
  std::string s2 = "at all";
}

void g() {
  std::string s = "excess";
  {
    std::string s = "or";
    h();
  }
}

void f() {
  std::string name { "Byron" };
  try {
    std::string s = "in";
    g();
  }
  catch(My_error e) {
    // ...
    std::cout << "Error id: " << e.errorMsg << '\n';
  }
}

struct Some_error {};

void fct(bool Some_wrong) {
  // ...
  if(Some_wrong)
    throw Some_error();
}

struct My_error2 : std::runtime_error {
  const char* what() const noexcept { return "My_error2"; }
};

int main() {
  //f(1);
  //f(0);
  f();
}
