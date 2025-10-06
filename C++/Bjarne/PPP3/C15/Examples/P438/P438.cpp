// P438.cpp 
import std;

void sizes(char ch, int i, int* p)
{
  std::cout << "the size of char is " << sizeof(char) << '=' << sizeof(ch) << '\n';
  std::cout << "the size of int is " << sizeof(int) << '=' << sizeof(i) << '\n';
  std::cout << "the size of int* is " << sizeof(int*) << '=' << sizeof(p) << '\n';
}

void sizeOfvector()
{
  std::vector<int> v(1000);
  std::cout << "the size of vector<int>(1000) is " << sizeof(v) << "\n";
}

void pointers()
{
  double* p = new double[4];
  double x = *p;
  double y = p[0];
  double z = p[2];

  *p = 7.7;
  p[2] = 9.9;

  double x1 = p[3];
  p[3] = 4.4;
  double y1 = p[0];
  //p[5] = 1.1;

  std::vector<int>* px = new std::vector<int>{ 7,8,9,5 };
  std::cout << px->size();
  std::cout << (*px).size();

  

}

int main()
{
  pointers();
  char c = 'a';

  int x = 17;
  int* pi = &x;         // pointer to int

  double e = 2.71828;
  double* pd = &e;      // pointer to double

  std::cout << "pi == " << pi << "; content of pi == " << *pi << '\n';
  std::cout << "pd == " << pd << "; content of pd == " << *pd << '\n';

  sizes(c, x, pi);

  sizeOfvector();


}
