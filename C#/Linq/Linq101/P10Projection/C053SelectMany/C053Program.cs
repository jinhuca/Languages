// SelectMany: Flattens collections into a single collection (similar to cross join in SQL)

using static System.Console;

string[] fruits_ = { "Grape", "Orange", "Apple" };
int[] amounts_ = { 1, 2, 3 };

var result_ = fruits_.SelectMany(f => amounts_, (f, a) => new
{
  Fruit = f,
  Amount = a
});

WriteLine("Selecting all values from each array, and mixing them:");
foreach(var o_ in result_)
  WriteLine(o_.Fruit + ", " + o_.Amount);