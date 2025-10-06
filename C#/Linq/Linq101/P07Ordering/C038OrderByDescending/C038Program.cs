using static System.Console;

// OrderByDescending: Sorts a collection in descending order.

string[] names_ = { "Ned", "Ben", "Susan" };

var result_ = names_.OrderByDescending(n => n);

WriteLine("Descending ordered list of names:");
foreach(var name_ in result_)
  WriteLine(name_);

