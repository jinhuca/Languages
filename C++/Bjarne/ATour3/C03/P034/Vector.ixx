export module Vector;

export class Vector {
public:
  Vector(int);
  double& operator[](int);
  int size();
private:
  double* elem;
  int sz;
};

export bool operator==(const Vector&, const Vector&);