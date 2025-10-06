// First: Retrieves first element from a collection. Throws exception if collection is empty.

string[] countries_ = { "Denmark", "Sweden", "Norway" };
var result_ = countries_.First(c => c.Length == 6);
Console.WriteLine($"First element with a length of 6 characters: {result_}");
