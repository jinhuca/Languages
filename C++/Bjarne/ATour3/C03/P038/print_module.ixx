import std;
export module print_module;

export void print(int value, int base = 10)    // print value in base "base"
{
  if (base == 10)
  {
    std::cout << "print value " << value << " in base 10" << std::endl;
  }
  else if (base == 16)
  {
    std::cout << "print value " << value << " in base 16" << std::endl;
  }
}

