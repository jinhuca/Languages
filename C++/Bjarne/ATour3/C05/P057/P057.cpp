import std;
import Vector;

P057::Vector gv(10);      // global variable; gv is destroyed at the end of the program

namespace P057
{
  Vector* gp = new Vector(100);   // Vector on free store; never implicitly destroyed

  void fct(int n)
  {
    Vector v(n);
    // ... use v ...
    {
      Vector v2(2 * n);
      // ... use v and v2 ...
    } // v2 is destroyed here
    // ... use v ...
  } // v is destroyed here

  Vector read(std::istream &is)
  {
    Vector v(1);
    for(double d; is >> d;)
      v.push_back(d);
    return v;
  }

  void initialize_vectors()
  {
    Vector v1 = { 1, 2, 3, 4, 5 };
    Vector v2 = { 1.23, 2.34, 3.45 };
  }
}

int main()
{
  using namespace P057;
  initialize_vectors();
  fct(10);
  Vector v = read(std::cin);
}
