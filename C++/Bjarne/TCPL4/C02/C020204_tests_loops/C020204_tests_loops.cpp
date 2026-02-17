// C020204_tests_loops.cpp 
import std;

bool accept1() {
  std::cout << "Do you want to proceed (y/n)?\n";   // write question
  char answer;
  std::cin >> answer;                               // read answer

  if (answer == 'y') return true;
  return false;
}

bool accept2() {
  std::cout << "Do you want to proceed (y/n)?\n";   // write question
  char answer;
  std::cin >> answer;                               // read answer
  switch(answer) {
    case 'y': 
      return true;
    case 'n': 
      return false;
    default: 
      std::cout << "I'll take that for a no.\n"; 
      return false;
  }
}

bool accept3() {
  int tries = 1;
  while (tries < 4) {
    std::cout << "Do yo want to proceed (y/n)?\n";   // write question
    char answer;
    std::cin >> answer;
    switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      std::cout << "Sorry, I don't understand that.\n";
      ++tries;
    }
  }
  std::cout << "I'll take that for a no.\n";
  return false;
}

int main() {
  if (accept1()) {
    std::cout << "You accepted.\n";
  }
  else {
    std::cout << "You did not accept.\n";
  }
}
