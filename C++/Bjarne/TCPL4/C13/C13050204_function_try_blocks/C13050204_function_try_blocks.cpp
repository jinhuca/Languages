// C13050204_function_try_blocks.cpp 
#include <iostream>
#include <vector>
#include <string>

class X {
  std::vector<int> vi;
  std::vector<std::string> vs;

public:
  X(int, int);
};

X::X(int sz1, int sz2)
try
: vi(sz1),    // construct vi with sz1 ints
  vs(sz2)     // construct vs with sz2 ints
{
  // ...
}
catch(std::exception& err) {  // exceptions thrown for vi and vs are caught here
  // ...
}

int main()

try {
  // ... do something ...
}
catch(...) {
  // ... handle exception ...
}


