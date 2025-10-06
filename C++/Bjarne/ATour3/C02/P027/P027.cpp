import std;

enum class Type { ptr, num };       // a Type can hold values ptr and num

struct Node
{
};

struct Entry
{
  std::string name;
  Type t;
  Node* p;
  int i;
};

void f(Entry* pe)
{
  if (pe->t == Type::num)
    std::cout << pe->i;
}

union Value
{
  Node* p;
  int i;
};

void g(Entry* pe)
{
  if (pe->t == Type::num)
    std::cout << pe->name;
}

int main()
{
}
