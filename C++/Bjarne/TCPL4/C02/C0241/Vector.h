#pragma once
class Vector {
public:
  Vector(int s);
  double& operator[](int);
  int size() const;
private:
  double* elem;
  int sz;
};