// Distinct: Removes duplicate elements from a collection.

using static System.Console;

int[] numbers_ = [1, 2, 2, 3, 5, 6, 6, 6, 8, 9];

var result_ = numbers_.Distinct();

WriteLine("Distinct removes duplicate elements:");
foreach(int number_ in result_)
  WriteLine(number_);
