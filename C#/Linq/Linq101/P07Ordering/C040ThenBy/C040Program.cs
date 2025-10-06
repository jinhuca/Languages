// ThenBy: Use after earlier sorting, to further sort a collection in ascending order.

using static System.Console;

string[] capitals_ = {
  "Berlin", "Paris", "Madrid", "Tokyo", "London", "Athens", "Beijing", "Seoul"
};

var result_ = capitals_.OrderBy(c => c.Length).ThenBy(c => c);

WriteLine("Ordered list of capitals, first by length and then alphabetical:");
foreach (var capital_ in result_)
  WriteLine(capital_);