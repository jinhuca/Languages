string[] words_ = { "hello", "wonderful", "linq", "beautiful", "world" };

foreach(var word in words_)
{
  if(word.Length <= 5)
    Console.WriteLine(word);
}
