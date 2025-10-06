// LastOrDefault: Retrieves last element from a collection, or default value if collection is empty.

using static System.Console;

string[] words_ = { "one", "two", "three" };
string[] empty_ = { };

var result_ = words_.LastOrDefault();
var resultEmpty_ = empty_.LastOrDefault();

WriteLine($"Last element in the words array contains: {result_}");
WriteLine($"Last element in the empty array does not exist: {resultEmpty_ == null}");