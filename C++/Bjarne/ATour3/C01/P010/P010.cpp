import std;

// sum will not modify its argument
double sum(const std::vector<double>& v) {
  double s = 0;
  for(auto& x : v)
    s += x;
  return s;
}

void f() {
  constexpr int dmv = 17;                   // dmv is a named constant
  int var = 17;                             // var is not a constant
  const double sqv = std::sqrt(var);        // sqv is a named constant, possibly computed at run time

  const std::vector<double> v { 1.2, 3.4, 4.5 };
  const double s1 = sum(v);                 // OK: sum(v) is evaluated at run time
  std::cout << s1 << std::endl;
  //constexpr double s2 = sum(v);           // error: sum(v) is not a constant expression

  //consteval double xy = 1.23;             //
}

constexpr double square(double x) { return x * x; }

constexpr double max1 = 1.4 * square(17);   // OK 1.4 * square(17) is a constant expression

int var = 17;
//constexpr double max2 = 1.4 * square(var);// error: var is not a constant expression
const double max3 = 1.4 * square(var);      // OK, may be evaluated at rum time

consteval double nth(double x, int n)       // assume 0<=n
{
  double res = 1;
  int i = 0;
  while(i < n) {           // while-loop: do while the condition is true
    res *= x;
    ++i;
  }
  return res;
}

consteval double square2(double x) { return x * x; }

void g(double x)
{
  constexpr double max2 = 1.4 * square2(17);

  //constexpr double max3 = square2(x);
}

int main() {
  f();
  std::cout << nth(3, 4) << '\n';
}
