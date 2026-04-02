// C160300_concrete_classes.cpp 
#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;
using namespace Chrono;

void f(Chrono::Date& d) {
  Date lvb_day{16,Month::dec, d.year()};

  if(d.day() == 29 && d.month() == Month::feb) {
    // ...
  }

  //if(midnight()) d.add_day(1);

  cout << "day after: " << d + 1 << endl;

  Date dd;    // initialized to the default date
  cin >> dd;
  if(dd == d) cout << "Hurray\n";
}

void f(vector<Date>& aa) {
  while(cin) {
    Date d;
    try {
      cin >> d;
    }
    catch(Date::Bad_date) {
      // ... my error handling code here ...
      continue;
    }
    aa.push_back(d);
  }
}

int main() {
  std::cout << "Hello World!\n";
}
