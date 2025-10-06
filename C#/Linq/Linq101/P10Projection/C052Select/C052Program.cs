// Select: Selects, projects and transforms elements in a collection.
// Can be overloaded to get element index.

using static System.Console;

string[] words_ = ["one", "two", "three"];

var result_ = words_.Select((w, i) => new
{
  Index = i,
  Value = w
});

WriteLine("Words with index and value:");
foreach(var word_ in result_)
  WriteLine($"Index {word_.Index} is {word_.Value}");