// C163_Concrete_Classes.cpp 
import std;
import Chrono;

using Date = Chrono::Date;
using Month = Chrono::Month;

void f(Date& d) {
  Date lvb_day { 16,Month::dec,d.year() };
  if(d.day() == 29 && d.month() == Month::feb) {

  }
  Date d1 = Date { 1, Month::jan, 1969 };
  std::cout << d1 << '\n';
}

void g() {
  Date d {};
  std::cin >> d;
  std::cout << d;
}

int main() {
  //Date d1 { 1,Month::apr,1993 };
  //f(d1);
  g();
}
