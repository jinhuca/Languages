// C0802_structures.cpp 
#include <iostream>

struct Address {
  const char* name;     // "Jim Dandy"
  int number;           // 61
  const char* street;   // "South St"
  const char* town;     // "New Providence"
  char state[2];        // 'N''J'
  const char* zip;      // "07974"
};

Address jd = { 
  "Jim Dandy", 
  61, 
  "South St", 
  "New Providence", 
  {'N', 'J'},
  "07974" 
};

void initialize_struct() {
  Address jd1;
  jd1.name = "Jim Dandy";
  jd1.number = 61;

  Address jd2 = { 
    "Jim Dandy", 
    61, 
    "South St", 
    "New Providence", 
    {'N', 'J'},
    "07974" 
  };
}

void assign_struct() {
  Address jd1;
  jd1 = jd; // assign one struct to another
}

void print_addr_via_variable(const Address p) {
  std::cout << "print address via variable:\n";
  std::cout << p.name << '\n'
    << p.number << ' ' << p.street << '\n'
    << p.town << '\n'
    << p.state[0] << p.state[1] << ' ' << p.zip << "\n\n";
}

void print_addr_via_reference(const Address& r) {
  std::cout << "print address via reference:\n";
  std::cout << r.name << '\n'
    << r.number << ' ' << r.street << '\n'
    << r.town << '\n'
    << r.state[0] << r.state[1] << ' ' << r.zip << "\n\n";
}

void print_addr_via_pointer(const Address* p) {
  std::cout << "print address via pointer:\n";
  std::cout << (*p).name << '\n'
    << (*p).number << ' ' << (*p).street << '\n'
    << (*p).town << '\n'
    << (*p).state[0] << (*p).state[1] << ' ' << (*p).zip << "\n\n";
}

void print_demo() {
  print_addr_via_variable(jd);
  print_addr_via_reference(jd);
  print_addr_via_pointer(&jd);
}

int main() {
  initialize_struct();
  assign_struct();
  print_demo();
}
