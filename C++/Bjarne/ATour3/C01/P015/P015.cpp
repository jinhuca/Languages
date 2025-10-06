import std;
using namespace std;

bool accept() {
  cout << "Do you want to proceed (y or n)?\n";     // write question
  char answer = 0;                                  // initialize to a value that will not appear on input
  cin >> answer;                                    // read answer

  if(answer == 'y')
    return true;
  return false;
}

bool accept2() {
  cout << "Do you want to proceed (y or n)?\n";     // write question
  char answer = 0;                                  // initialize to a value that will not appear on input
  cin >> answer;                                    // read answer

  switch(answer) {
  case 'y':
    return true;
  case 'n':
    return false;
  default:
    cout << "I'll take that for a no.\n";
    return false;
  }
}

struct Point {
  int x;
  int y;
};

void action() {
  while(true) {
    cout << "enter action:\n";      // request action
    string act;
    cin >> act;                     // read character into a string
    Point delta { 0,0 };            // Point holds an {x, y} pair

    for(char ch : act) {
      switch(ch) {
      case 'u':   // up
      case 'n':   // north
        ++delta.y;
        break;
      case 'r':   // right
      case 'e':   // east
        ++delta.x;
        break;
      default:
        cout << "I freeze!\n";
        break;
      }
    }
  }
}

void do_something(std::vector<int>& v) {
  if(auto n = v.size(); n != 0) {
    // ... we get here if n != 0 ...
  }
}

void do_somethingElse(std::vector<int>& v) {
  if(auto n = v.size()) {
    // ... get here if n != 0 ...
    std::cout << "Size of passed vector is: " << n << '\n';
  }
  else
  {
    std::cout << "Passed vector is empty.\n";
  }
}

int main() {
  //accept2();
  std::vector<int> v {  };
  do_somethingElse(v);
}
