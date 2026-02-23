// C030403_function_objects.cpp 
import std;

template<typename T>
class Less_than {
  const T val;    // value to compare against
public:
  Less_than(const T& v):val(v){ }
  bool operator()(const T& x) const { return x < val; }   // call operator
};

Less_than<int> lti(42);                     // lti(i) will compare to 42 using < (i<42)
Less_than<std::string> lts("Backus");       // lts(s) will compare s to "Backus" using < (s<"Backus")

void fct(int n, const std::string& s) {
  bool b1 = lti(n);     // true if n < 42
  bool b2 = lts(s);     // true if s < "Backus"
}

template<typename C, typename P>
int count(const C& c, P pred) {
  int cnt = 0;
  for (const auto& x : c)
    if (pred(x))
      ++cnt;
  return cnt;
}

void f(const std::list<std::string>& lst, const std::string& s) {
  std::cout << count(lst, Less_than<std::string>{s}) << '\n';
}

void g(const std::list<std::string>& lst, const std::string s) {
  std::cout << count(lst, [&](const std::string& a) {return a < s; }) << '\n';
}

template<typename C, typename Oper>
void for_all(C& c, Oper op) {
  for (auto& x : c)
    op(*x);
}

void user() {
  std::vector<std::unique_ptr<int>> v;
  v.push_back(std::make_unique<int>(1));
  v.push_back(std::make_unique<int>(2));
  for (const auto& x : v)
    std::cout << *x << '\n';

  for_all(v, [](int& x) { x *= 10; });
  for (const auto& x : v)
    std::cout << *x << '\n';
}

int main() {
  fct(1, "Bjarne");
  user();
}
