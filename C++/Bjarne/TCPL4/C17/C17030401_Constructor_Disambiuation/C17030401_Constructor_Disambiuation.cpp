// C17030401_Constructor_Disambiguation.cpp 
import std;

struct X {
  X() :data { 0 } {}
  X(std::initializer_list<int> lst) {
    for(auto e : lst) {
      data.push_back(e);
    }
  }
  X(int a) : data { a } {}
private:
  std::vector<int> data;
};

void g() {
  X x0 {};
  X x2 { 1 };
  X x3 { 1, 2 };
  X x4(4);
}

int main() {
  g();
}
