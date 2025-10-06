import std;

std::vector<int> vec;       // vec is global (a global vector of integers)

struct Record {
  std::string name;         // name is a member or Record (a string member)
  // ...
};

// fct is global (a global function)
void fct(int arg)
// arg is local (an integer argument)
{
  std::string motto { "Who dares wins" };     // motto is local
  auto p = new Record { "Hume" };             // p points to an unnamed Record (created by new)
  // ...
  delete p;
}

int main() {
  std::cout << "Hello World!\n";
}
