import std;
using namespace std::literals::string_literals;

std::string compose(const std::string& name, const std::string& domain)
{
  return name + '@' + domain;
}

int main()
{
  auto cat = "Cat"s;
  auto dog = "Dog";
  const auto address_ = compose("dmr", "bell-labs.com");
  std::cout << address_ << '\n';
}
