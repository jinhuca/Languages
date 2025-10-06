// C170402_Base_Initializers.cpp 
import std;

class B1 {
  B1() {}         // has default constructor
};

class B2 {
  B2(int i) {}    // no default constructor
};

struct D1 :B1, B2 {
  D1(int i) : B1 {}, B2 { i } {}    //
};

struct D2 :B1, B2 {
  D2(int i) : B1 {}, B2 { i } {}
};

struct D3 : B1, B2 {
  //D3(int) {}      // error: B2 requires an int initializer
};

int main() {
  std::cout << "Hello World!\n";
}
