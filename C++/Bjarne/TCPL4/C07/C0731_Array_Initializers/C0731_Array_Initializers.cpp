// C0731_Array_Initializers.cpp
import std;

void initialize_with_list() {
  int v1[] = { 1, 2, 3, 4, 5 };
  int v11[] { 0, 1, 2, 3, 4 };
  char v2[] = { 'a', 'b', 'c', 0 };

  //char v3[2] { 'a','b', 0 };     // compile-time error: too many initializers
  char v4[3] { 'a','b', 0 };
  int v5[10] { 1, 2, 3, 4 };        // it's OK: filled with defaults: too few initializers
}

void no_copy_assign() {
  int v5[3] { 1, 2, 3 };
  //int v6[3] = v5;             // no copy, no assignment for array.
}

int main() {
  initialize_with_list();
}
