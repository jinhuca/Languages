// P196.cpp : Pass-by-reference.
import std;

void init(std::vector<double>& v)
{
  for (int i = 0; i < v.size(); ++i)
    v[i] = i;
}

void g(int x)
{
  std::vector<double> vd1(10);        // small vector
  std::vector<double> vd2(1000000);   // large vector
  std::vector<double> vd3(x);         // vector of some unknown size

  init(vd1);
  init(vd2);
  init(vd3);
}

int main()
{
  g(5);
}
