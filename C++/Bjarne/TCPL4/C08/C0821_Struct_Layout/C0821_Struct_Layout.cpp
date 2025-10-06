// C0821_Stuct_Layout.cpp 
import std;

struct Readout {
  char hour;      // [0:23]
  int value;
  char seq;       // sequence mark ['a':'z']
};

void f() {
  Readout r { 'a', 9, 'g' };
  auto a1 = &r.hour;
  auto a2 = &r.value;
  auto a3 = &r.seq;

  auto s1 = sizeof(r.hour);
  auto s2 = sizeof(r.value);
  auto s3 = sizeof(r.seq);
  auto s = sizeof(r);
}

struct R2 {
  int value;
  char hour;      // [0:23]
  char seq;       // sequence mark ['a':'z']
};

void g() {
  R2 r { 8, 'b', 'k' };
  auto a1 = &r.hour;
  auto a2 = &r.value;
  auto a3 = &r.seq;

  auto s1 = sizeof(r.hour);
  auto s2 = sizeof(r.value);
  auto s3 = sizeof(r.seq);
  auto s = sizeof(r);
}

int main() {
  f();
  g();
}
