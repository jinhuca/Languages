import std;

void f() {
  char v[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };   // array of 6 characters
  char* p = &v[3];                                // pointer to the 4th character in the array 
  char x = *p;                                    // *p is the object that p points to
  std::cout << *p << std::endl;
  std::cout << x << std::endl;
}

void copy_fct() {
  int v1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int v2[10];                                     // to become a copy of v1

  for(auto i = 0; i != 10; ++i)                  // copy elements
  {
    v2[i] = v1[i];
  }

  for(auto i = 0; i != 10; ++i)                  // loop copied v2
  {
    std::cout << v2[i] << std::endl;
  }
}

int main() {
  f();
  copy_fct();
}
