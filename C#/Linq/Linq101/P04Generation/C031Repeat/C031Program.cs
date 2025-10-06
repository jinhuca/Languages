using static System.Console;

// Repeat: Creates a collection of repeated elements, where first argument is value to repeat,
// and second argument is number of times to repeat.

string word_ = "Banana";
var result_ = Enumerable.Repeat(word_, 5);

WriteLine("String is repeated 5 times:");
foreach(var str in result_)
{
  WriteLine(str);
}
