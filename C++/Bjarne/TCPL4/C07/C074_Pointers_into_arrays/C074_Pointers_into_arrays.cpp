// C074_Pointers_into_arrays.cpp 
import std;

extern "C" int strlen(const char*);

void f() {
  char v[] = "Annemarie";
  char* p = v;    // implicit conversion of char[] to char*
  int a = strlen(p);
  int b = strlen(v);      // implicit conversion of char[] to char*
  //v = p;          // error: cannot assign to array
}

int main() {
  int v[] { 1, 2, 3, 4 };
  int* p1 = v;                // pointer to initial element (implicit conversion)
  int* p2 = &v[0];            // pointer to initial element
  int* p3 = v + 4;            // pointer to one-beyond-last element

  int* p4 = v - 1;            // before the beginning, undefined: don't do it
  int* p5 = v + 7;            // beyond the end, undefined: don't do it

  f();
}
