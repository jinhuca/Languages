export module Buffer;
import std;

export template<typename T, int N>
struct Buffer
{
  constexpr int size() { return N; }
  T elem[N];
};

export template<char* s>
void outs()
{
  std::cout << s;
}
