// C1002.cpp
import std;

void use() {
  std::ifstream in(R"(file.txt")");   // input file
  if(!in) {
    std::cerr << "no file.\n";
    return;
  }

  std::regex pat { R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S. postal code pattern

  int lineno = 0;
  for(std::string line; std::getline(in, line);) {
    ++lineno;
    std::smatch matches;    // matched strings go here
    if(std::regex_search(line, matches, pat)) {
      std::cout << lineno << ": " << matches[0] << '\n';
      if(1 < matches.size() && matches[1].matched) {
        std::cout << "\t: " << matches[1] << '\n';
      }
    }
  }
}

int main() {
  use();
}
