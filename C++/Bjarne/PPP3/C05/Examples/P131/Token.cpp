class Token
{
public:
  char kind;                                          // what kind of token
  double value;                                       // for numbers: a value
  explicit Token() {}                                 // default construct
  Token(char k) : kind{ k }, value{ 0.0 } {}          // construct from one value
  Token(char k, double v) :kind{ k }, value{ v } {}   // construct from two values
};