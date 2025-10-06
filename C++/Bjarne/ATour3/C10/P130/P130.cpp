// P130.cpp : Regular Expression.
#include <fstream>
#include <iostream>
#include <regex>

void match_regex()
{
  std::string s = "AAAAAAAABBBBBC";
  std::regex pat{ R"(^A*B+C?$)" };
  if (std::regex_match(s, pat))
    std::cout << "matched." << std::endl;
  else
    std::cout << "no matched." << std::endl;
}

void search_regex()
{
  std::ifstream in(R"(C:\Users\JinHu_PC\Documents\Repositories\ATourOfCpp3\C10\P130\x64\Debug\file.txt)");
  if (!in)                           // check that the file was opened
  {
    std::cerr << "no file\n";
    return;
  }
  std::regex pat{ R"(\w{2}\s*\d{5}(-\d{4})?)" };   // U.S. postal code pattern

  int lineno = 0;
  for (std::string line; std::getline(in, line);)
  {
    ++lineno;
    std::smatch matches;                                  // matched strings go here
    if (std::regex_search(line, matches, pat))
    {
      std::cout << lineno << ": " << matches[0] << '\n';  // the complete match
      if (matches.size() > 1 && matches[1].matched)        // if there is a sub-pattern and if it is matched
        std::cout << "\t: " << matches[1] << '\n';        // sub-match
    }
  }
}

int main()
{
  match_regex();
  search_regex();
}
