#include <stdio.h>

enum Weekday
{
  Monday = 1,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};

int main()
{
  enum Weekday day = Tuesday;
  printf("%d", day);
  return 0;
}