export module Vector;

import std;

export class Vector
{
public:
  Vector(int s);
  double& operator[](int i) const;
  int size() const;
  ~Vector();
private:
  double* elem;
  int sz;
};