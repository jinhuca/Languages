import std;

struct Node
{
  int x;
  int y;
};

struct Entry
{
  std::string name;
  std::variant<Node *, int> v;
};

void f(Entry *pe)
{
  if(std::holds_alternative<int>(pe->v))
    std::cout << get<int>(pe->v);
}

int main()
{
  std::cout << "Hello World!\n";
}
