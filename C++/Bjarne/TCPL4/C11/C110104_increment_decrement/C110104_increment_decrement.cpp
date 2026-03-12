// C110104_increment_decrement.cpp 
#include <iostream>

// the folowing functions are to copy a zero-terminated C-style string q to p
//
void cpy_1(char* p, const char* q) {
  int length = static_cast<int>(strlen(q));
  for(int i = 0; i <= length; i++)
    p[i] = q[i];
}

void cpy_2(char* p, const char* q) {
  int i;
  for(i = 0; q[i] != 0; i++)
    p[i] = q[i];
  p[i] = 0;
}

void cpy_3(char* p, const char* q) {
  while(*q != 0) {
    *p = *q;
    p++;
    q++;
  }
  *p = 0;
}

void cpy_4(char* p, const char* q) {
  while(*q != 0) {
    *p++ = *q++;
  }
  *p = 0;
}

void cpy_5(char* p, const char* q) {
  while((*p++ = *q++) != 0) { }
}

void cpy_6(char* p, const char* q) {
  while(*p++ = *q++);
}

int main() {
  const char* qt = "hello C++!";
  char* pt = new char {};
  cpy_1(pt, qt);
  cpy_2(pt, qt);
  cpy_3(pt, qt);
  cpy_4(pt, qt);
  cpy_5(pt, qt);
  cpy_6(pt, qt);
}
