// C120501_ptf_as_argument.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::string;
using std::sort;

using CFT = int(const void*, const void*);

/*
* Sort the "n" elements of vector "base" into increasing order
* using the comparison function pointed to by "cmp".
* The elements are of size "sz".
* 
* Shell sort (Knuth, Vol3, pg84)
*/
void ssort(void* base, size_t n, size_t sz, CFT cmp) {
  for(int gap = n / 2; 0 < gap; gap /= 2)
    for(int i = gap; i != n; i++)
      for(int j = i - gap; 0 <= j; j -= gap) {
        char* b = static_cast<char*>(base);   // necessary cast
        char* pj = b + j * sz;                // &base[j]
        char* pjg = b + (j + gap) * sz;       // &base[j+gap]
        if(cmp(pjg, pj) < 0) {                // swap base[j] and base[j+gap]
          for(int k = 0; k != sz; k++) {
            char temp = pj[k];
            pj[k] = pjg[k];
            pjg[k] = temp;
          }
        }
      }
}

struct User {
  const char* name;
  const char* id;
  int dept;
};

vector<User> heads = {
  {"Ritchie D.M.",   "dmr",    11271},
  {"Sethi R.",       "ravi",   11272},
  {"Szymanski T.G.", "tgs",    11273},
  {"Schryer N.L.",   "nls",    11274},
  {"Schryer N.L.",   "nls",    11275},
  {"Kernighan B.W.", "bwk",    11276}
};

void print_id(vector<User>& v) {
  for(auto& x : v)
    cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

int cmp1(const void* p, const void* q) {    // compare name strings
  return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

int cmp2(const void* p, const void* q) {    // compare dept numbers
  return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}

int cmp3(const User* p, const User* q) {    // compare ids
  return strcmp(p->id, q->id);
}

void ssort_with_pointer_to_function() {
  cout << "Heads in alphabetical order:\n";
  ssort(&heads[0], 6, sizeof(User), cmp1);
  print_id(heads);
  cout << '\n';

  cout << "Heads in order of department number:\n";
  ssort(&heads[0], 6, sizeof(User), cmp2);
  print_id(heads);
  cout << '\n';
}

void sort_with_lambda() {
  cout << "Heads in alphabetical order:\n";
  sort(heads.begin(), heads.end(), [](const User& x, const User& y) { return x.name < y.name; });
  print_id(heads);
  cout << '\n';

  cout << "Heads in order of department number:\n";
  sort(heads.begin(), heads.end(), [](const User& x, const User& y) { return x.dept < y.dept; });
  print_id(heads);
  cout << '\n';
}

int main() {
  ssort_with_pointer_to_function();
  sort_with_lambda();
}
