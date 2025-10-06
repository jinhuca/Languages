// AsEnumerable: casts a collection to IEnumerable of the same type.

string[] names_ = { "John", "Suzy", "Dave" };
var result_ = names_.AsEnumerable();

Console.WriteLine("Iterating over IEnumerable collection");
foreach (var name in result_)
  Console.WriteLine(name);
