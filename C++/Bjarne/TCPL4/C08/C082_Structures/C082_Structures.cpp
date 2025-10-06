// C082_Structures.cpp
import std;

struct Address {
  const char* name;       // "Jim Dandy"
  int number;             // 61
  const char* street;     // "South St"
  const char* town;       // "New Providence"
  char state[2];          // 'N' 'J'
  const char* zip;        // "07974"
};

Address address;

void initialize_struct_members(Address& addr) {
  addr.name = "Jim Dandy";
  addr.number = 61;
}

void initialize_struct(Address& addr) {
  addr = {
  "Jim Dandy",
  61,
  "South St",
  "New Providence",
  {'N','J'},
  "07974"
  };
}

void print_struct_by_pointer(const Address* p) {
  std::cout << "Name:\t" << p->name << '\n'
    << "Number:\t" << p->number << '\n'
    << "Street:\t" << p->street << '\n'
    << "Town:\t" << p->town << '\n'
    << "State:\t" << p->state[0] << p->state[1] << '\n'
    << "Zip:\t" << p->zip << "\n\n";
}

void print_struct_by_reference(const Address& r) {
  std::cout << "Name:\t" << r.name << '\n'
    << "Number:\t" << r.number << '\n'
    << "Street:\t" << r.street << '\n'
    << "Town:\t" << r.town << '\n'
    << "State:\t" << r.state << '\n'
    << "Zip:\t" << r.zip << "\n\n";
}

int main() {
  initialize_struct_members(address);
  initialize_struct(address);
  print_struct_by_pointer(&address);
  print_struct_by_reference(address);
}
