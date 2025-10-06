// Skip: Skips specified number of elements in a collection.

using static System.Console;

string[] words_ = ["one", "two", "three", "four", "five", "six"];
var result_ = words_.Skip(4);

WriteLine("Skips the first 4 words:");
foreach(var word_ in result_)
  WriteLine(word_);