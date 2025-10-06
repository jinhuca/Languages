import PPP;

class Token
{
public:
  char kind;                                          // what kind of token
  double value;                                       // for numbers: a value
  explicit Token() {}                                 // default construct
  Token(char k) : kind{ k }, value{ 0.0 } {}          // construct from one value
  Token(char k, double v) :kind{ k }, value{ v } {}   // construct from two values
};

Token get_token()
{

}

double expression()
{
  double left = term();                 // read and evaluate a Term
  Token t = get_token();                // get the next token
  while (true) {
    switch (t.kind) {
    case '+':
      left += term();                   // evalute Term and add
      t = get_token();
      break;
    case '-':
      left -= term();                   // evaluate Term and substract
      t = get_token();
      break;
    default:
      return left;                      // finally: no more + or -; return the answer
    }
  }
}

double primary()
{
  Token t = get_token();
  switch (t.kind) {
  case '(':
  {
    double d = expression();
    t = get_token();
    if (t.kind != ')')
      PPP::error("')' expected");
    return d;
  }
  case '8':
    return t.value;
  default:
    PPP::error("primary expected");
  }
}

double term()
{
  double left = primary();
  Token t = get_token();
  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = get_token();
      break;
    case '/':
    {
      double d = primary();
      if (d == 0)
        PPP::error("divide by zero");
      left /= d;
      t = get_token();
      break;
    }
    default:
      return left;
    }
  }
}
