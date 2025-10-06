using static System.Console;

// Reverse: Reverses elements in a collection.
char[] characters_ = { 's', 'a', 'm', 'p', 'l', 'e' };
var result_ = characters_.Reverse();
WriteLine("Characters in reverse order:");
foreach(var character in result_)
  WriteLine(character);
