import std;

class Vector
{
public:
  Vector(int s)                   // construct a Vector
    : elem { new double[s] }, sz { s }
  {
  }

  double &operator[](int i)       // element access: subscripting
  {
    return elem[i];
  }

  int size() const
  {
    return sz;
  }

private:
  double *elem;                   // pointer to the elements
  int sz;                         // the number of elements
};

double read_and_sum(int s)
{
  Vector v(s);                    // make a vector of s elements
  for (int i = 0; i != v.size(); ++i)
    std::cin >> v[i];             // read into elements

  double sum = 0;
  for (int i = 0; i != v.size(); ++i)
    sum += v[i];

  return sum;
}

int main()
{
  Vector v(6);                    // a Vector with 6 elements
  std::cout << read_and_sum(3) << std::endl;
}
