// P045.cpp : Invariant
import Vector;
import std;

namespace std
{
  class length_error;
}

void test(int n)
{
  try
  {
    Vector v(n);
  }
  catch(std::length_error& err)
  {
    std::cerr << err.what();
    throw;
  }
  catch(std::bad_alloc& err)
  {
    std::cerr << err.what();
    std::terminate();
  }
}

int main()
{
  test(-27);
}
