export module Matrix;

export class Matrix {};

export Matrix operator+(const Matrix& x, const Matrix& y)
{
  Matrix res;
  return res;
}

// complicated and error-prone 20th century style
export Matrix* add(const Matrix& x, const Matrix& y)
{
  Matrix* p = new Matrix;
  // ...
  return p;
}