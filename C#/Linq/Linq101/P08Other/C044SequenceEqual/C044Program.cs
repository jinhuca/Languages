// SequenceEqual: Checks whether two collections are equal.
// Use StringComparer.OrdinalIgnoreCase parameter to ignore case.

using static System.Console;

string[] words_ = { "one", "two", "three" };
string[] wordsSame_ = { "one", "two", "three" };
string[] wordsOrder_ = { "two", "three", "one" };
string[] wordsCase_ = { "one", "TWO", "three" };

var resultSame_ = words_.SequenceEqual(wordsSame_);
var resultOrder_ = words_.SequenceEqual(wordsOrder_);
var resultCase_ = words_.SequenceEqual(wordsCase_);
var resultCaseIgnored_ = words_.SequenceEqual(wordsCase_, StringComparer.OrdinalIgnoreCase);

WriteLine("SequenceEqual on two identical arrays:");
WriteLine(resultSame_);

WriteLine("SequenceEqual on two differently ordered but otherwise identical arrays:");
WriteLine(resultOrder_);

WriteLine("SequenceEqual on two differently cased but otherwise identical arrays:");
WriteLine(resultCase_);

WriteLine("SequenceEqual on two differently cased but otherwise identical arrays, where case is ignored:");
WriteLine(resultCaseIgnored_);