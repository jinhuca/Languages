// D047.cpp
import std;

int main()
{
  std::cout << "Enter the name of the person you want to write to: ";
  std::string name;
  std::cin >> name;

  std::cout << "Enter the age of the person you are writing to: ";
  int age;
  std::cin >> age;
  
  std::cout << "Enter a friend's name: ";
  std::string friend_name;
  std::cin >> friend_name;

  std::cout << "Dear " << name << ",\n";
  std::cout << "\tHow are you? I am fine. I miss you.\n";
  std::cout << "Have you seen " << friend_name << " lately?\n";
 
  if (age < 12)
    std::cout << "Next year you will be " << age + 1 << ".";
  else if (age == 17)
    std::cout << "Next year you will be able to vote.";
  else if (age > 70)
    std::cout << "Are you retired?";

  std::cout << '\n';
  std::cout << "Yours sincerely,\n\nJohn Doe\n\n";

  int $PATH = 1;
  std::cout << $PATH << '\n';
}
