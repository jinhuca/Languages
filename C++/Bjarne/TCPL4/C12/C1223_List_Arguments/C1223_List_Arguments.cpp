// C1223_List_Arguments.cpp 
import std;

template<typename T>
void f1(std::initializer_list<T>) {

}

struct S {
  int a;
  std::string s;
};
void f2(S) {}

template<typename T, int N>
void f3(const T(&r)[N]) {}

void f4(int) {}

void g() {
  f1({ 1,2,3,4 });      // T is int and the initializer_list has size() 4
  f2({ 1,"MKS" });    // f2(S{1,"MKS"})
  f3({ 1,2,3,4 });              // T is int and N is 4
  f4({ 1 });                      // f4(int{1})
}

int main() {
  g();
}
