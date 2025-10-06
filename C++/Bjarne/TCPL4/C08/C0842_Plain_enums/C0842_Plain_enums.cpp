// C0842_Plain_enums.cpp 
import std;

namespace N1 {
  // enum Traffic_light { red, yellow, green };
  enum Warning { green, yellow, orange, red };  // error: name conflicts if uncomment the above definition

  void f() {
    // Warning a1 = 7;              // error: no int->Warning conversion
    int a2 = green;                 // OK: green is in scope and converts to int
    int a3 = Warning::yellow;       // OK: Warning->int conversion
    Warning a4 = Warning::green;    // OK
  }
}

namespace N2 {
  enum Traffic_light { red, yellow, green };
  void f(Traffic_light x) {
    if(x == 9) {/*...*/ }                   // OK (but Traffic_light doesn't have a 9)
    if(x == red) {/*...*/ }                 // error: two reds in scopes of two enum definitions
    if(x == N1::Warning::red) {/*...*/ }    // OK (Ouch!)
    if(x == Traffic_light::red) {/*...*/ }  // OK
  }
}

int main() {

}
