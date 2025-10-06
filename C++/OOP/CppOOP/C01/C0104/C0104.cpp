// C0104.cpp
#include <iostream>
#include "Date.h"

int main()
{
  Date date(2024, 7, 13);
  std::cout << date.date_string() << '\n';
  return 0;
}
