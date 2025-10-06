// Any: Checks if any elements in a collection satisfies a specified condition.

using static System.Console;

string[] names_ = { "Bob", "Ned", "Amy", "Bill" };

var result_ = names_.Any(n => n.StartsWith("B", StringComparison.Ordinal));

WriteLine("Does any of the names start with the letter 'B':");
WriteLine(result_);