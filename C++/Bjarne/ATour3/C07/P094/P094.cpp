import std;
using namespace std;

template<typename T>
class Less_than
{
  const T val;
public:
  Less_than(const T &v) :val { v } {}
  bool operator()(const T &x) const { return x < val; }
};

Less_than ltl { 42 };
Less_than lts { "Backus"s };
Less_than<std::string> lts2 { "Naur" };

void fct(int n, const std::string& s)
{
  bool b1 = ltl(n);       // true if n < 42
  std::cout << b1 << std::endl;
  bool b2 = lts(s);       // true if s < "Backus"
  std::cout << b2 << std::endl;
}

template<typename C, typename P>
int count(const C& c, P pred)     // assume that C is a container and P is a predicate on its elements
{
  int cnt = 0;
  for(const auto &x : c)
    if(pred(x))
      ++cnt;
  return cnt;
}

void f(const std::vector<int> vec, int x)
{
  std::cout << "number of values less than " << x << " : " << count(vec, Less_than { x }) << std::endl;
}

int main()
{
  fct(42, "Hello");
  f(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8}, 4);
}
