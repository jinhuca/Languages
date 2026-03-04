// C0822_Struct_Names.cpp 
import std;

struct Link {
  Link* previous;
  Link* next;
};

//struct No_good {
//  No_good member;     // error: recursive definitions
//};

struct List;            // struct name declaration; List to be defined later

struct DLink {
  DLink* pre;
  DLink* suc;
  List* member_of;
  int data;
};

struct List {
  DLink* head;
};

int main() {
  std::cout << "Hello World!\n";
}
