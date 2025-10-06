// C07321_Raw_Characters.cpp
import std;

void f() {
  std::string s = "\\w+\\\\\\w+";
  std::string s1 = R"(\w+\\\w+)";
  const char* r1 = R"("quoted string")";
  std::string s2 = R"("quoted string")";
}

int main() {
  f();
}
