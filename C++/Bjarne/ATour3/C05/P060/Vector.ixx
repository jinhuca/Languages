import std;
export module Vector;

namespace P060
{
  export class Vector                       // A container
  {
  public:
    explicit Vector(int s);                 // constructor: acquire resources
    Vector(std::initializer_list<double>);  // initialize with a list of doubles  
    ~Vector();                              // destructor: release resources
    double &operator[](int i) const;
    int size() const;
    void push_back(double);                 // add element at end, increasing the size by one
  private:
    double *elem;
    int sz;
  };
}