// C1122_Arrays.cpp 
import std;

char* save_string(const char* p) {
  char* s = new char[std::strlen(p) + 1];
  std::strcpy(s, p);
  return s;
}

std::string save_string2(const char* p) {
  return std::string(p);
}

int main(int argc, char* argv[]) {
  if (argc < 2) std::exit(1);
  //char* p = save_string(argv[1]);
  //delete[] p;
  std::string s = save_string2(argv[1]);
}
