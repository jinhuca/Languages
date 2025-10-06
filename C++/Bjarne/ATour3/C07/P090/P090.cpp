// P090.cpp
import std;
import Buffer;

Buffer<char, 1024> glob;  // global buffer of characters (statically allocated)

void fct()
{
  Buffer<int, 10> buf;    // local buffer of integers (on the stack)
  std::cout << buf.size() << std::endl;
}

char arr[] = "Weird workaround!";

void use()
{
  outs<arr>();
}

int main()
{
  fct();
  use();
}
