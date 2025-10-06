// C1001StringSamples.cpp
import std;

std::string compose(const std::string& name, const std::string& domain) {
  return name + '@' + domain;
}

void compose_strings() {
  auto str = compose("dmr", "bell-labs.com");
  std::cout << str << '\n';
}

int main() {
  compose_strings();
}
