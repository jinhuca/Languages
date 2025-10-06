// GroupBy: Projects elements of a collection into groups by key.

int[] numbers_ = { 10, 15, 20, 25, 30, 35 };
var result_ = numbers_.GroupBy(n => n % 10 == 0);
Console.WriteLine("GroupBy has created two groups:");
foreach(IGrouping<bool, int> group in result_)
{
  Console.WriteLine(group.Key == true ? "Divisible by 10" : "Not Divisible by 10");

  foreach(var number in group)
  {
    Console.WriteLine(number);
  }
}
