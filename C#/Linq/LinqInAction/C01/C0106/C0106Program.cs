string[] words_ = { "hello", "wonderful", "Linq", "beautiful", "world" };
var shortWords_ =
  from word in words_
  where word.Length <= 5
  select word;

foreach(var word in shortWords_)
{
  Console.WriteLine(word);
}