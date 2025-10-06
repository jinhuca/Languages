// P124.cpp
import std;

class Token
{
public:
  char kind;                                          // what kind of token
  double value;                                       // for numbers: a value
  explicit Token() {}                                 // default construct
  Token(char k) : kind{ k }, value{ 0.0 } {}          // construct from one value
  Token(char k, double v) :kind{ k }, value{ v } {}   // construct from two values
};

/*
Token get_token()                     // function to read a token from cin
{
  
}
*/

void tryToken()
{
  Token t1;
  t1.kind = '+';
  t1.value = 0;

  Token t2;
  t2.kind = '8';
  t2.value = 3.14;

  Token tt = t1;
  if (tt.kind != t1.kind)
    std::cerr << "impossible!";
  tt = t2;
  std::cout << tt.value << '\n';

  Token t3{ '+' };
  Token t4{ '8',11.5 };
  Token t5;
}

std::vector<Token> tok;

int main()
{
  tryToken();
  //while(std::cin)
  //{
  //  //Token t = get_token();
  //  //tok.push_back(t);
  //}
}
