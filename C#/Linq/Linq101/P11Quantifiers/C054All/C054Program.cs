// All: Checks if all elements in a collection satisfies a specifies condition.

using static System.Console;

string[] names_ = ["Bob", "Ned", "Amy", "Bill"];

var result_ = names_.All(n => n.StartsWith("B", StringComparison.Ordinal));

WriteLine("Does all of the names start with the letter 'B':");
WriteLine(result_);
