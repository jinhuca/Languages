void g()
{
  static_assert(4 <= sizeof(int), "integers are too small");  // check integer size
}

constexpr double C = 299792.458;    // km/s

void f(double speed)
{
  constexpr double local_max = 160.0 / (60 * 60);
  //static_assert(speed < C, "can't go that fast");       // error: speed must be a constant
  static_assert(local_max < C, "can't go that fast!");    // OK
}

void user(int sz) noexcept
{
  
}

int main()
{
  g();
  f(120);
}
