using static System.Console;

// Indices and ranges
char[] vowels = { 'a', 'e', 'i', 'o', 'u' };
char lastElement = vowels[^1];    // 'u'
WriteLine(lastElement);
char secondToLast = vowels[^2];   // 'o'
WriteLine(secondToLast);

char[] firstTwo = vowels[..2];
WriteLine(firstTwo);
char[] lastThree = vowels[2..];
WriteLine(lastThree);
char[] middleOne = vowels[2..3];
WriteLine(middleOne);
char[] lastTwo = vowels[^2..];
WriteLine(lastTwo);

Index last = ^1;
Range firstTwoRange = 0..2;
char[] firstTwo_ = vowels[firstTwoRange];
WriteLine(firstTwo_);

var subSentence = new Sentence();
foreach (var word in subSentence[1..3])
{
  WriteLine(word);
}

class Sentence
{
  private string[] words = "The quick brown fox".Split();
  public string this[Index index] => words[index];
  public string[] this[Range range] => words[range];
}