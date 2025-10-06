export module Vector;      // defining the module called "Vector"

export class Vector
{
public:
  Vector(int);
  double& operator[](int i) const;
  int size() const;
  void print() const;
private:
  double* elem;
  int sz;
};

export bool operator==(const Vector& v1, const Vector& v2);
