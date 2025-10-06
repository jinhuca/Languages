// P150.cpp 
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[])
{
  if(argc < 2) {
    std::cerr << "arguments expected\n";
    return 1;
  }

  std::filesystem::path p { argv[1] };
  std::cout << p << " " << std::filesystem::exists(p) << '\n';
}
