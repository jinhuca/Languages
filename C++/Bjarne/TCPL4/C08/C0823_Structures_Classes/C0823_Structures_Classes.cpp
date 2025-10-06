// C0823_Structures_Classes.cpp
import std;

struct Point {
  int x, y;
};

Point px;                   // global variable initialized to default

void init_point() {
  Point py = px;            // initialized with global variable
  Point p0;                 // danger: uninitialized in local scope
  Point p1 {};              // default construction: {{},{}}; that is {0,0}
  Point p2 { 1 };         // the second member is default constructed: {1, {}}; that is {1,0}
  Point p3 { 1,2 };   // {1,2}
}

struct Points {
  std::vector<Point> elem;    // must contain at least one Point
  Points(Point p0) { elem.push_back(p0); }
  Points(Point p0, Point p1) { elem.push_back(p0); elem.push_back(p1); }
};

void init_points() {
  //Points x0;                // error: no default constructor since Points define constructors explicitly
  Points x1 { Point{1,1} };   // one Point
  Points x2 { {1,2},{2,1} };    // two points
}

struct Address {
  std::string name;
  int number;
  std::string street;
  std::string town;
  char state[2];
  char zip[5];

  Address(const std::string& n, int nu, const std::string& s, const std::string& t, const std::string& st, int z);
};

Address::Address(const std::string& n, int nu, const std::string& s, const std::string& t, const std::string& st, int z)
  : name { n }, number { nu }, street { s }, town { t } {
  if(st.size() != 2)
    throw std::invalid_argument("State abbreviation should be two characters.");
  state[0] = st[0];
  state[1] = st[1];

  std::ostringstream ost;
  ost << z;
  std::string zi { ost.str() };
  switch(zi.size()) {
  case 4: case 5:
    for(int i = 0; i != zi.size(); ++i)
      zip[i] = zi[i];
    break;
    //zip[0] = zi[0];
    //zip[1] = zi[1];
    //zip[2] = zi[2];
    //zip[3] = zi[3];
    //zip[4] = zi[4];
    //break;
  //case 4:
  //  zip[0] = zi[0];
  //  zip[1] = zi[1];
  //  zip[2] = zi[2];
  //  zip[3] = zi[3];
  //  break;
  default:
    throw std::invalid_argument("unexpected ZIP code format.");
  }
}

void init_Address() {
  Address jd = {
    "Jim Dandy",
    61,
    "South St",
    "New Providence",
    "NJ",
    7974
  };
  Address jd2("John", 33, "North St", "Old Port", "NW", 1234);
}

void init_char_array() {
  char id[5] = { 'a','b','c','d','e' };
}

int main() {
  init_point();
  init_Address();
  init_char_array();
}
