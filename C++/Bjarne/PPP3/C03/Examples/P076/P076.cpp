// P076.cpp 
import std;

int main()
// simple dictionary: list of sorted words
{
  std::vector<std::string> words;
  for (std::string temp; std::cin >> temp;)    // read whitespace-separated words
  {
    words.push_back(temp);
  }
  std::cout << "Number of words: " << words.size() << '\n';

  std::ranges::sort(words);                 // sort the words

  for (int i = 0; i < words.size(); ++i)
  {
    if (i == 0 || words[i - 1] != words[i])
    {
      std::cout << words[i] << '\n';
    }
  }
}
