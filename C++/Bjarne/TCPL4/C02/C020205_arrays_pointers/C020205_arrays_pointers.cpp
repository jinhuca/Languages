// C020205_arrays_pointers.cpp 
import std;

void array_pointer_demo() {
  char v[6];    // array of 6 characters (5 + null terminator)
  std::cout << v[0] << '\n';   // uninitialized, value is indeterminate / undefined behavior

  char* p;
  //std::cout << *p << '\n';  // uninitialized pointer, value is indeterminate 
                              // undefined behavior results in error, crash, or garbage output

  const int size = 6;
  char v1[size] = "Hello";  // array initialized with string literal (includes null terminator)]

  p = &v1[3];  // pointer points to the 4th character of the array (index 3)
  char c = *p;   // dereference pointer to get the character 'l'
}

void copy_fct() {
  int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int v2[10];     // to become a copy of v1

  for(auto i = 0; i < 10; ++i) {
    v2[i] = v1[i];   // copy each element from v1 to v2
  }
}

void print() {
  int v[] = {0, 1,2, 3, 4, 5, 6, 7, 8, 9};
  for(auto x : v) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  for(auto x : {10,21,32,43,54,65,76,87,98}) {
    std::cout << x << ' ';
  }
}

void increment() {
  int v[] = {0, 1,2, 3, 4, 5, 6, 7, 8, 9};
  for(auto& x : v) {
    ++x;   // increment each element of the array
  }
}

// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
int count_x(char* p, char x) {
  if(p == nullptr) {
    return 0;   // if pointer is null, return 0 occurrences
  }
  int count = 0;
  for(; *p != 0; ++p)
    if(*p == x) {
      ++count;   // increment count if the current character matches x
    }
  return count;
}

int main() {
  //array_pointer_demo();
  //copy_fct();
  print();
  char arr[] = "Hello, world!";
  std::cout << count_x(arr, 'o') << '\n';  // count occurrences of 'o' in the string
}
