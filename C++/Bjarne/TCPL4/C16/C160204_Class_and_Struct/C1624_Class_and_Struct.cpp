// C1624_Class_and_Struct.cpp 
import std;

class Date1 {
  int d, m, y;          // private by default
public:
  Date1(int dd, int mm, int yy);
  void add_year(int n);
};

class Date2 {
private:                // explicitly declared as private
  int d, m, y;
public:                 // explicitly declared as public
  Date2(int dd, int mm, int yy);
  void add_year(int n);
};

class Date3 {
public:
  Date3(int dd, int mm, int yy);
  void add_year(int n);
private:
  int d, m, y;
};

class Date4 {
public:
  Date4(int dd, int mm, int yy);
private:
  int d, m, y;
public:
  void add_year(int n);
};

int main() {
  std::cout << "Hello World!\n";
}
