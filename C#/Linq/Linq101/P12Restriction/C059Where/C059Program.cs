// Where: Filters elements from a collection to satisfy a specified condition.
// Use overloaded Index to pass index.

using System.Diagnostics;
using static System.Console;

int[] numbers_ = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

var result_ = numbers_.Where((n, i) => n % 3 == 0 && i >= 5);

WriteLine("Numbers divisible by 3 and indexed >= 5:");
foreach(var number_ in result_)
  WriteLine(number_);