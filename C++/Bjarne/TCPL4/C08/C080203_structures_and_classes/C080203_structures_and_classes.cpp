// C080203_structures_and_classes.cpp 
#include <iostream>
#include <string>
#include <algorithm>

struct Point {
  int x, y;
};

Point p0;                 // global variable initialized by zero-ed member-wise 

void construct_struct_with_default_constructor() {
  Point p1;               // uninitialized
  Point p2 = { 1, 2 };    // initialized via initializer list
  Point p3 = p2;          // initialized via copy of another struct
  Point p4 { 1 };         // initialized via initializer list with default member initialization
}

struct Address {
  std::string name;       // "Jim Dandy"
  int number;             // 61
  std::string street;   // "South St"
  std::string town;     // "New Providence"
  char state[2];        // 'N''J'
  char zip[5];          // "07974"

  Address(const std::string& n,
    int num,
    const std::string& st,
    const std::string& t,
    const std::string& s,
    int z);
};

Address::Address(
  const std::string& n,
  int num,
  const std::string& st,
  const std::string& t,
  const std::string& s,
  int z) 
  : name(n), number(num), street(st), town(t) {
  state[0] = s[0];
  state[1] = s[1];
  std::transform(std::to_string(z).begin(), std::to_string(z).end(), zip, [](char c) { return c; });
}

void construct_address_with_constructor() {
  Address jd = { "Jim Dandy", 61, "South St", "New Providence", {'N', 'J'}, 7974 };
}

int main() {
  construct_struct_with_default_constructor();
  construct_address_with_constructor();
}
