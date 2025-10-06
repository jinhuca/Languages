// ToDictionary: Converts collection into a Dictionary with Key and Value.

int[] numbers_ = { 1, 2, 3, 4 };
var result_ = numbers_.ToDictionary(k => k, v => (v % 2) == 1 ? "Odd" : "Even");
Console.WriteLine("Numbers labeled Odd and Even in dictionary:");
foreach(var dic in result_)
  Console.WriteLine($"Value {dic.Key} is {dic.Value}");
