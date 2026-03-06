// C0942_Switch_statements.cpp 
import std;

void f(int i) {
  switch(i) {
    // case 2.7:        // error: floating-point uses for case
      //...
  case 2:
    // ...
    break;
  case 4:
    // ...
    break;
    // case 4-2:       // error: 2 used twice in case labels
    break;
  }
}

void g(int i) {
  int x = 0;
  switch(i) {
  case 0:
    ++x;                      // uninitialized
    // int y = 3;             // error: declaration can be bypassed (explicitly initialized)
    // std::string s;         // error: declaration can be bypassed (explicitly initialized)
    // break;                 // beware: fall through
  case 1:
    //++x;
    //++y;
    //s = "nasty";
    break;
  }
}

enum class Vessel { cup, glass, goblet, chalice };

void problematic(Vessel v) {
  switch(v) {
  case Vessel::cup: /* ... */ break;
  case Vessel::glass: /* ... */ break;
  case Vessel::goblet: /* ... */ break;
  }
}

int main() {

}
