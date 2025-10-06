namespace C013ToDictionary;

internal class C013Program
{
  static void Main()
  {
    English2German[] english2German_ =
    {
      new() { EnglishSalute = "Good morning", GermanSalute = "Guten Morgen" },
      new() { EnglishSalute = "Good day", GermanSalute = "Guten Tag" },
      new() { EnglishSalute = "Good evening", GermanSalute = "Guten Abend" },
    };

    var result_ = english2German_.ToDictionary(k => k.EnglishSalute, v => v.GermanSalute);
    Console.WriteLine("Values inserted into dictionary:");
    foreach (KeyValuePair<string, string> dic in result_)
      Console.WriteLine($"English salute {dic.Key} is {dic.Value} in German");
  }
}

class English2German
{
  public string EnglishSalute { get; set; }
  public string GermanSalute { get; set; }
}