// 	LastOrDefault: Retrieves last element from a collection, or default value if collection is empty.

// Note: While Last will throw an exception if array...
//       ...is empty, LastOrDefault gracefully returns null.

using static System.Console;

string[] words_ = { "one", "two", "three" };

var result_ = words_.LastOrDefault(w => w.Length == 3);
var resultNoMatch_ = words_.LastOrDefault(w => w.Length == 2);

WriteLine($"Last element in the words array having a length of 3: {result_}");
WriteLine($"Last element in the empty array having a length of 2 does not exist: {resultNoMatch_ == null}");
