// P077.cpp 
import std;

int main()
{
  std::string disliked = "Broccoli";

  std::vector<std::string> words;
  for(std::string temp; std::cin>>temp;)
  {
    words.push_back(temp);
  }

  for(std::string s : words)
  {
    if(s == disliked)
    {
      std::cout << "BLEEP" << '\n';
    }
    else
    {
      std::cout << s << '\n';
    }
  }
}
