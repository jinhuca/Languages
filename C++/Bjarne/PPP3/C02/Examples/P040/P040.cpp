// P040.cpp : find repeated words
import std;

int main()
{
  int number_of_words = 0;
  std::string previous;
  std::string current;
  while (std::cin >> current)
  {
    ++number_of_words;
    if (previous == current)
      std::cout << "word number " << number_of_words << " repeated: " << current << '\n';
    previous = current;
  }
}
