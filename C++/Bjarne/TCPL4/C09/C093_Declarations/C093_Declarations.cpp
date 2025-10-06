// C093_Declarations.cpp 
import std;

void f(std::vector<std::string>& v, int i, const char* p) {
  if(p == nullptr) return;
  if(i < 0 || i >= v.size()) throw std::out_of_range("vector access out of range.");
  std::string s = v[i];
  if(s == p) {
    // ...
  }
  // ...
}

void g() {
  std::string s1;
  s1 = "The best is the enemy of the good.";
  // ...
  std::string s2 { "Voltaire" };
}

constexpr int max = 1024;
void input() {
  int buf[max];
  int count = 0;
  for(int i; std::cin >> i;) {
    if(i < 0) throw std::invalid_argument("buffer");
    if(count == max) throw std::overflow_error("buffer");
    buf[count++] = i;
  }
}

int main() {

}
