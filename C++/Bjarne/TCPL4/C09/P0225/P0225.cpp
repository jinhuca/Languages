// P0225.cpp
#include <iostream>
#include <vector>

void error(const char* str)
{
  
}

void f(std::vector<std::string>& v, int i, const char* p)
{
  if(p == nullptr) return;
  if(i < 0 || v.size() <= i)
    error("bad index");
  std::string s = v[i];
  if(s==p)
  {
    // ...
  }
}

void use()
{
  std::string s1;
  s1 = "The best is the enemy of the good.";

  std::string s2 { "Voltaire" };
}

int main()
{

}
