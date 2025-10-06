// P204.cpp : bitset
import std;

int main()
{
  std::bitset<9> bs1 { "110001111" };
  std::bitset<9> bs2 { 0b1'1000'1111 };
  std::cout << bs1.to_string() << '\n';
}
