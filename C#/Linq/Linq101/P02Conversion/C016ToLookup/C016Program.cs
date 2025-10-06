// ToLookup: Converts a collection into a Lookup, grouped by key.

string[] words_ = { "one", "two", "three", "four", "five", "six", "seven" };
var result_ = words_.ToLookup(w => w.Length);

for (int i = 1; i <= 5; i++)
{
  Console.WriteLine($"Elements with a length of {i}:");
  foreach (var word in result_[i])
  {
    Console.WriteLine(word);
  }
}

