// P143.cpp
#include <chrono>
#include <iostream>

void demo_integer_format()
{
  std::cout << 1234 << ' '
    << std::hex << 1234 << ' '
    << std::oct << 1234 << ' '
    << std::dec << 1234 << '\n';
}

void demo_floating_point_format()
{
  constexpr double d = 123.456;
  std::cout << d << ";" << std::endl                // use the default format for d
    << std::scientific << d << ";" << std::endl     // use 1.23456e2 style format for d
    << std::hexfloat << d << ";" << std::endl       // use hexadecimal notation for d
    << std::fixed << d << ";" << std::endl          // use 123.456 style format for d
    << std::defaultfloat << d << '\n';              // use the default format for d
}

void demo_precision()
{
  std::cout.precision(8);
  std::cout << "precision(8): " << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';

  std::cout.precision(4);
  std::cout << "precision(4): " << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';
  std::cout << 1234.56789 << '\n';
  std::cout << 1234.43 << '\n';
}

void demo_datetime()
{
  std::cout << "birthday: " << std::chrono::November / 26 / 2021 << std::endl;
  std::cout << "zt: " << std::chrono::zoned_time{ std::chrono::current_zone(), std::chrono::system_clock::now() } << std::endl;
}

int main()
{
  demo_precision();
  demo_integer_format();
  demo_floating_point_format();
  demo_precision();
  demo_datetime();
}
