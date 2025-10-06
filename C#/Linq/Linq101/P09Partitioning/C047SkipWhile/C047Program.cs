// SkipWhile: Skips elements in a collection while specified condition is met.

using static System.Console;

string[] words_ = ["one", "two", "three", "four", "five", "six"];
var result_ = words_.SkipWhile(w => w.Length == 3);

WriteLine("Skips words while the condition is met:");
foreach (var word_ in result_)
  WriteLine(word_);