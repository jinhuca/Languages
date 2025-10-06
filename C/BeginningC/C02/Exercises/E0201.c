// Exercise 2-1. Write a program that prompts the user to enter a distance in inches and then
// outputs that distance in yards, feet, and inches.
// (There are 12 inches in a foot, and 3 feet in a yard.)
#include <stdio.h>

int main()
{
  printf("Enter a distance in inches: ");
  int inches = 0, yards = 0, feet = 0, temp = 0;
  scanf("%d", &inches);
  yards = inches / 36;
  feet = (inches - yards * 36) / 12;
  inches = inches - yards * 36 - feet * 12;

  printf("Distance is %d yards %d feet %d inches", yards, feet, inches);
  return 0;
}