// C042_Strings.cpp 
#include <string>
#include <iostream>

std::string compose(const std::string& name, const std::string& domain) {
  return name + '@' + domain;
}

std::string compose2(std::string& s1, const std::string& s2) {
  return s1 += '@' + s2;
}

void m1() {
  auto addr = compose("dmr", "bell-labs.com");
}

void m2(std::string& s1, std::string& s2) {
  s1 = s1 + '\n';
  s2 += '\n';
}

std::string name = "Neils Stroustrup";

void m3() {
  std::string s = name.substr(6, 10);
  name.replace(0, 5, "nicholas");
  name[0] = toupper(name[0]);
  std::cout << name << '\n';
}

std::string incantation;
void respond(const std::string& answer) {
  if(answer == incantation) {     // compare strings against each other

  }
  else if(answer == "yes") {      // compare string against string literal
  }
}
int main() {
  m3();
}
