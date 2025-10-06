// TakeWhile: Takes elements in a collection while specified condition is met,
// starting from first element.

using static System.Console;

int[] numbers_ = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

var result_ = numbers_.TakeWhile(n => n < 5);

WriteLine("Takes numbers one by one, and stops when condition is no longer met:");
foreach(int number_ in result_)
  WriteLine(number_);