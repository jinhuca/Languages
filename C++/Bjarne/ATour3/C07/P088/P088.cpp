import std;
import Vector;

void write1(Vector<std::string>& vs) {
  for(int i = 0; i != vs.size(); ++i) {
    std::cout << vs[i] << ' ';
  }
  std::cout << '\n';
}

void write2(Vector<std::string>& vs) {
  for(auto& s : vs) {
    std::cout << s << ' ';
  }
  std::cout << '\n';
}

void iterateIntVector(Vector<int>& vs) {
  for(auto& e : vs) {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

void demoStringVectors() {
  Vector<std::string> vs(7);
  vs[0] = "Hello";
  vs[1] = "Modern";
  vs[2] = "C++";

  write1(vs);
  write2(vs);
}

void demoIntVectors() {
  Vector<int> vs1(3);
  vs1[0] = 0;
  vs1[1] = 1;
  vs1[2] = 2;
  iterateIntVector(vs1);
}

int main() {
  demoStringVectors();
  //demoIntVectors();
}
