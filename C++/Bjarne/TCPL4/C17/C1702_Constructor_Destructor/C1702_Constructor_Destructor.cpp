// C1702_Constructor_Destructor.cpp 
import std;

struct Tracer {
  std::string mess;
  Tracer(const std::string& s) :mess { s } { std::clog << mess; }
  ~Tracer() { std::clog << "--" << mess; }
};

void f(const std::vector<int>& v) {
  Tracer tr { "in f()\n" };
  for (auto x : v) {
    Tracer tr { std::string{"v loop "} + std::to_string(x) + '\n' };
  }
}

int main() {
  std::vector<int> v { 1, 2, 3, 4, 5, 6 };
  f(v);
}
