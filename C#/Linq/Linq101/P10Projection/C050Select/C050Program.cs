// Select: Selects, projects and transforms elements in a collection.

using static System.Console;

decimal[] numbers_ = [3.4M, 8.33M, 5.225M];

var result_ = numbers_.Select(n => Math.Floor(n));

WriteLine("Numbers rounded down:");
foreach(int number_ in result_)
  WriteLine(number_);