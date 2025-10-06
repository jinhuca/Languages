// P129.cpp : string_view.
import std;
using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

std::string cat(std::string_view sv1, std::string_view sv2)
{
  std::string res { sv1 };
  return res += sv2;
}

void printSV(std::string_view str) // now a std::string_view
{
  std::cout << str << '\n';
}

void f()
{
  std::string king = "Harold";
  auto s1 = cat(king, "William");  // string and const char
  auto s2 = cat(king, king);   // string and string
  auto s3 = cat("Edward", "Stephen"sv);  // const char* and string_view
  auto s4 = cat("Canute"sv, king);  // string_view and string
  std::string_view x = std::string_view{&king[0], 2};
  auto s5 = cat({ &king[0],2 }, "Henry"sv); // HaHenry
  auto s6 = cat({ &king[0],2 }, { &king[2],4 }); // Harold
}

void print_lower(std::string_view sv1)
{
  for(char ch : sv1)
  {
    std::cout << static_cast<char>(std::toupper(ch));
  }
}

int main()
{
  f();
  using namespace std::literals::string_view_literals;
  std::string_view sv1 = "hello world!"sv;
  print_lower(sv1);

  return 0;
}
