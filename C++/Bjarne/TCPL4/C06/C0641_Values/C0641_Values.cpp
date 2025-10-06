// C0641_Values.cpp 
import std;

void f(std::vector<std::string>& vs) {
  std::vector<std::string> v2 = std::move(vs);    // move vs to v2
}

int main() {
  std::vector<std::string> v { "hello ","world!" };
  f(v);
}
