// C020205_arrays_pointers.cpp 
import std;

void array_pointer_demo() {
  char v[6];    // array of 6 characters (5 + null terminator)
  std::cout << v[0] << '\n';   // uninitialized, value is indeterminate / undefined behavior

  char* p;
  //std::cout << *p << '\n';  // uninitialized pointer, value is indeterminate 
                              // undefined behavior results in error, crash, or garbage output
}

int main() {
  array_pointer_demo();
}
