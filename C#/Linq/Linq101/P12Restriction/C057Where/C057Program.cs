// Where: Filters elements from a collection to satisfy a specified condition

using static System.Console;

int[] numbers_ = [5, 10, 15, 20, 25, 30];

var result_ = numbers_.Where(n => n >= 15 && n <= 25);

WriteLine("Numbers being >= 15 and <= 25:");
foreach(var number_ in result_)
  WriteLine(number_);