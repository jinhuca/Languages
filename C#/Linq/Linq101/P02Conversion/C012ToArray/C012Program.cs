// ToArray: Converts type to a new array.

int[] numbers_ = { 1, 2, 3, 4 };
var result_ = numbers_.ToArray();

Console.WriteLine("New array contains identical values:");
foreach (var number in result_)
  Console.WriteLine(number);
