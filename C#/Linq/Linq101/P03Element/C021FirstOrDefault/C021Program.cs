// FirstOrDefault: Retrieves first element from a collection, or default value if collection is empty.
// Note: While First() will throw an exception if array ...
//       ... is empty, FirstOrDefault gracefully returns null.

string[] countries_ = { "Denmark", "Sweden", "Norway" };
string[] empty = { };

var result_ = countries_.FirstOrDefault();
var resultEmpty_ = empty.FirstOrDefault();

Console.WriteLine($"First element in the countries array contains: {result_}");
Console.WriteLine($"First element in the empty array does not exist: {resultEmpty_ == null}");
