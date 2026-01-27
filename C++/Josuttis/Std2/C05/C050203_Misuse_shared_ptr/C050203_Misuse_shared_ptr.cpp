// C050203_Misuse_shared_ptr.cpp 
import std;

void f1() {
  int* p = new int;
  std::shared_ptr<int> sp1(p);
  std::shared_ptr<int> sp0(sp1);
  //std::shared_ptr<int> sp2(p); // ERROR: double delete
}

int main() {
  try {
    f1();
  }
  catch (std::exception e) {
    std::cout << "Exception - " << e.what() << '\n';
  }
}
