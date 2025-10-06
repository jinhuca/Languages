// C0201.cpp :
import std;

void UseCounterValue(int i)
{
  std::cout << i << '\n';
}

int main()
{
  for (int i = 0; i < 5; ++i) { UseCounterValue(i); }
  for (int i = 0; i < 5; ++i) { UseCounterValue(i); }
  for (int i = 0; i < 5; ++i) { UseCounterValue(i); }
}
