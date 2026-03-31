#pragma once
class Date {
public:
  void add_month(int n) { m += n; }
private:
  int d, m, y;
};

