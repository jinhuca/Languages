using static System.Console;

// ThenByDescending: Use after earlier sorting, to further sort a collection in descending order.

var dates_ = new[]
{
  new DateTime(2015, 3, 1),
  new DateTime(2014, 7, 1),
  new DateTime(2013, 5, 1),
  new DateTime(2015, 1, 1),
  new DateTime(2015, 7, 1)
};

var result_ = dates_
  .OrderByDescending(d => d.Year)
  .ThenByDescending(d => d.Month);

WriteLine("List of dates first ordered by year descending, and then by month descending:");
foreach(var dt_ in result_)
  WriteLine(dt_.ToString("yyyy/MM/dd"));