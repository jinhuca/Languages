using static System.Console;

// OrderBy: Sorts a collection in ascending order.
int[] numbers_ = { 7, 9, 5 };
var result_ = numbers_.OrderBy(n => n);

WriteLine("Ordering list of numbers:");
foreach(var number in result_)
  WriteLine(number);
