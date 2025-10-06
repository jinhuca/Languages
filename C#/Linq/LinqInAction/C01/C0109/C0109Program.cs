string[] words_ = ["hello", "wonderful", "linq", "beautiful", "world"];

var groups_ =
  from word in words_
  orderby word ascending
  group word by word.Length into lengthGroups_
  orderby lengthGroups_.Key descending
  select new { Length = lengthGroups_.Key, Words = lengthGroups_ };

foreach(var group_ in groups_)
{
  Console.WriteLine("Words of length " + group_.Length);
  foreach(var word_ in group_.Words)
  {
    Console.WriteLine("   " + word_);
  }
}