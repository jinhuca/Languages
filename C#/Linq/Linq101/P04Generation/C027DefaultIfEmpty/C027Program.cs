// DefaultIfEmpty: If a collection is empty, its default value is returned.
// Default value depends on collection type.

using static System.Console;

string[] emptyStr_ = [];
int[] emptyInt_ = [];
string[] words_ = ["one", "two", "three"];

var resultStr_ = emptyStr_.DefaultIfEmpty(); // Default is null for string

var resultInt_ = emptyInt_.DefaultIfEmpty(); // Default is 0 for int

var resultWords_ = words_.DefaultIfEmpty(); // Not empty, so words array is just copied

WriteLine("resultStr has one element with a value of null:");
WriteLine(resultStr_.Count() == 1 && resultStr_.First() == null);

WriteLine("resultInt has one element with a value of 0:");
WriteLine(resultInt_.Count() == 1 && resultInt_.First() == 0);

WriteLine("resultWords has same content as words array:");
WriteLine(resultWords_.SequenceEqual(words_));