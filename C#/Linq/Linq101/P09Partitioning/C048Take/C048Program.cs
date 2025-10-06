// Take: Takes specified number of elements in a collection, starting from first element.

using static System.Console;

int[] numbers_ = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
var result_ = numbers_.Take(5);

WriteLine("Takes the first 5 numbers only:");
foreach (var number_ in result_)
  WriteLine(number_);