// C160212_Static_Members.cpp 
import std;

class Date {
  int d, m, y;
  static Date default_date;
public:
  Date(int dd = 0, int mm = 0, int yy = 0);
  static void set_default(int dd, int mm, int yy);
};

Date Date::default_date { 4,5,1946 };

void Date::set_default(int d, int m, int y) {
  default_date = { d,m,y };
}

Date::Date(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}


int main() {

}
