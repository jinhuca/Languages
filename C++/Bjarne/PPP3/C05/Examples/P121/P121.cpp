// P121.cpp 

import PPP;

int main()
{
  std::cout << "Please enter expression (we can handle +, -, *, and /)\n";
  std::cout << "add an x to end expression (e.g., 1 + 2 * 3x): ";
  int lval = 0;
  int rval = 0;
  std::cin >> lval;         // read left-most operand
  if (!std::cin)
    PPP::error("no first operand");

  for (char op; std::cin >> op;) {    // read operator and right-hand operand repeatedly
    if (op != 'x')
      std::cin >> rval;
    if (!std::cin)
      PPP::error("no second operand");
    switch (op)
    {
    case '+':
      lval += rval;                   // add: lval = lval + rval
      break;
    case '-':
      lval -= rval;                   // subtract: lval = lval - rval
      break;
    case '*':
      lval *= rval;                   // multiply: lval = lval * rval
      break;
    case '/':
      lval /= rval;                   // divide: lval = lval / rval
      break;
    default:                          // not another operator: print result
      std::cout << "result: " << lval << '\n';
      return 0;
    }
  }
  PPP::error("bad expression");
}
