// C0701.cpp
import std;
import Vector;

void f() {
  Vector<char> vc(200);   // Vector of 200 characters
}

void write(const Vector<std::string>& vs) {
  for(int i = 0; i != vs.size(); ++i) {
    std::cout << vs[i] << '\n';
  }
}

//void write2(Vector<std::string>& vs) {
//  for(auto x : vs) {
//    std::cout << x << '\n';
//  }
//}

int main() {
  f();
}
