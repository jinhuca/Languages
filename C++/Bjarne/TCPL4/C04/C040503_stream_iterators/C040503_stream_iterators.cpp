// C0453_StreamIterators.cpp
import std;

std::ostream_iterator<std::string> oo { std::cout };

void simple_ostream_demo() {
  *oo = "Hello, ";
  ++oo;
  *oo = "world!.\n";
}

auto ff() -> bool {
  std::string from, to;
  std::cin >> from >> to;     // get source and target file names

  std::ifstream is { from };
  std::istream_iterator<std::string> ii { is };
  std::istream_iterator<std::string> eos {};    //

  std::ofstream os { to };
  std::ostream_iterator<std::string> oo { os, "\n" };

  std::vector<std::string> b { ii, eos };
  std::sort(b.begin(), b.end());

  std::unique_copy(b.begin(), b.end(), oo);

  return !is.eof() || !os;
}

int main() {
  //simple_ostream_demo();
  auto result = ff();
}
