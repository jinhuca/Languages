// P141.cpp
import std;

std::vector<int> read_integers(std::istream &is)
{
  std::vector<int> res;
  for(int i; is >> i;)
    res.push_back(i);
  return res;
}

std::vector<int> read_integers(std::istream &is, const std::string &terminator)
{
  std::vector<int> res;
  for(int i; is >> i;)
    res.push_back(i);

  if(is.eof())
    return res;
  if(is.fail())
  {
    is.clear();
    std::string s;
    if(is >> s && s == terminator)
      return res;
    is.setstate(std::ios_base::failbit);
  }
  return res;
}

void read_with_default_terminator()
{
  for(const auto &x : read_integers(std::cin))
    std::cout << x << " ";
}

void read_with_terminator()
{
  auto v = read_integers(std::cin, "stop");
  for(const auto &x : v)
    std::cout << x << std::endl;
}

int main()
{
  auto result = read_integers(std::cin);
  //read_with_terminator();
}
