// P148.cpp 
import std;

void test()
{
  std::ostringstream oss;
  oss << "{temperature, " << std::scientific << 123.4567890 << "}";
  std::cout << oss.view() << '\n';
}

template<typename Target = std::string, typename Source = std::string>
Target to(Source arg)
{
  std::stringstream buf;
  Target result;

  if(!(buf << arg)                  // write arg into stream
    || !(buf >> result)             // read result from stream
    || !(buf >> std::ws).eof())     // is anything left in stream
    throw std::runtime_error { "to<>() failed" };

  return result;
}

void convert()
{
  const auto x1 = to<std::string, double>(1.2);
  std::cout << x1 << std::endl;

  const auto x2 = to<std::string>(1.2);
  std::cout << x2 << std::endl;

  const auto x3 = to<>(1.2);
  std::cout << x3 << std::endl;

  const auto x4 = to(1.2);
  std::cout << x4 << std::endl;
}

int main()
{
  test();
  //convert();
}
