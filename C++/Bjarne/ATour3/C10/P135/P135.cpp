// P135.cpp 
#include <iostream>
#include <regex>

void test()
{
  std::string input = "aa as; asd ++e~asdf asdfg";
  std::regex pat { R"(\s+(\w+))" };
  for(std::sregex_iterator p(input.begin(), input.end(), pat); p != std::sregex_iterator {}; ++p)
    std::cout << (*p)[1] << '\n';
}

int main()
{
  test();
}
