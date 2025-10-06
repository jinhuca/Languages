void assign() {
  int x = 2;
  int y = 3;
  x = y;                // x becomes 3; so we get x==y
}

void assignPointers() {
  int x = 2;
  int y = 3;
  int* p = &x;
  int* q = &y;          // p != q and *p != *q
  p = q;                // p becomes &y; now p == q, so *p == *q
}

void assignReferences() {
  int x = 2;
  int y = 3;
  int& rx = x;
  int& ry = y;
  rx = ry;
}

int main() {
  assignReferences();
}
