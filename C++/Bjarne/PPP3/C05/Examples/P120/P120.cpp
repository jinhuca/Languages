// P120.cpp : First attempt for calculator.
import PPP;

int main()
{
  std::cout << "Please enter expression (we can handle + and -): ";
  int lval = 0;
  int rval = 0;
  char op = 0;
  int res = 0;
  std::cin >> lval >> op >> rval;

  if (op == '+')
    res = lval + rval;
  else if (op == '-')
    res = lval - rval;
  std::cout << "Result: " << res << '\n';
}
