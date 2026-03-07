// C1034_Temporary_objects.cpp 
import std;

void f(std::string& s1, std::string& s2, std::string& s3) {
  const char* cs = (s1 + s2).c_str();
  std::cout << "cs = " << cs;
  if (8 < std::strlen(cs = (s2 + s3).c_str()) && cs[0] == 'a') {
    std::cout << cs;
  }
}

void f2(std::string& s1, std::string& s2, std::string& s3) {
  std::cout << s1 + s2;
  std::string s = s1 + s2;
  if (s.length() < 8 && s[0] == 'a') {
    std::cout << s;
  }
}

void g(const std::string& s1, const std::string& s2) {
  std::cout << s1 + " " + s2;
}

void h(std::string& s1, std::string& s2) {
  const std::string& s = s1 + s2;
  std::string ss = s1 + s2;
  g(s, ss);
}

int main() {
  std::string a1 = "hello";
  std::string a2 = "world";
  std::string a3 = "Joe";
  f(a1, a2, a3);
  f2(a1, a2, a3);
  h(a1, a2);
}
