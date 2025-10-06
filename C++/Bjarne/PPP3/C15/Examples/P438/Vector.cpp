class Vector      // a very simplified vector of doubles (like vector<double>)
{
  int sz;                             // the size
  double* elem;                       // pointer to the first element (of type double)
public:
  Vector(int s);                      // constructor: allocate s doubles,
                                      // let elem point to them and sz hold the size (s)
  int size() const { return sz; }     // the current size
};