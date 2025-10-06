// OrderBy: Sorts a collection in ascending order.

var dates_ = new DateTime[]
{
  new(2015, 2, 15),
  new(2015, 3, 25),
  new(2015, 1, 5)
};

var result_ = dates_.OrderBy(d => d);

Console.WriteLine("Ordered list of dates:");
foreach(var date in result_)
  Console.WriteLine(date.ToString("yyyy/MM/dd"));