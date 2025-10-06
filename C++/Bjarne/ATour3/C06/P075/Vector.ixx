export module Vector;

export class Vector
{
public:
  explicit Vector(int s);               // constructor: establish invariant, acquires resources
  ~Vector() { delete[] elem; }          // destructor: release resources

  Vector(const Vector &a);              // copy constructor
  Vector &operator=(const Vector &a);   // copy assignment

  Vector(Vector &&a) noexcept;                   // move constructor
  Vector &operator=(Vector &&a) noexcept;        // move assignment

  double& operator[](int i);
  const double &operator[](int i) const;

  int size() const;
private:
  double *elem;
  int sz;
};