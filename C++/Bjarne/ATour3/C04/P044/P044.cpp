import Vector;
import std;

void compute1(const Vector& v)
{
  std::cout << v[13] << std::endl;
}

Vector compute2(const Vector& v)
{
  return v;
}

void compute3(const Vector& v)
{
}

void f(Vector& v)
{
  try
  {
    compute1(v);
    Vector v2 = compute2(v);
    compute3(v2);
  }
  catch(const std::out_of_range& err)
  {
    std::cerr << err.what() << '\n';
  }
}

int main()
{
  auto v = Vector(3);
  f(v);
}
