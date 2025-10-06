// C170301_Init_No_Constructors.cpp
import std;

void f() {
  int a { 1 };
  char b = 'c';
  char* p { nullptr };
  p = &b;
}

struct Work {
  std::string author;
  std::string name;
  int year;
};

void g() {
  Work s9 {
    "Beethoven",
    "Symphony No.9",
    1824
  };      // memberwise initialization

  Work currently_playing { s9 };    // copy initialization
  Work none {};                     // default initialization
}

struct Buf {
  int count;
  char buf[16 * 1024];
};

Buf buf0;                       // statically allocated, so initialized by default

void k() {
  Buf buf1;                         // leave elements uninitialized
  Buf buf2 {};                      // I really want to zero out those elements
  int* p1 = new int;                // *p1 is uninitialized
  int* p2 = new int {};             // *p2 == 0
  int* p3 = new int { 7 };          // *p3 = 7
}

int main() {
  f();
  g();
  k();
}
