using System.Text.RegularExpressions;
using static System.Console;

namespace C0987;

public class C0987Program
{
  static void F0987()
  {
    WriteLine(Regex.Match("color", @"colou?r").Success);
    WriteLine(Regex.Match("colour", @"colou?r").Success);
    WriteLine(Regex.Match("colouur", @"colou?r").Success);
  }

  static void F0988()
  {
    Match m = Regex.Match("any color you like", @"colou?r");
    WriteLine(m.Success);
    WriteLine(m.Index);
    WriteLine(m.Length);
    WriteLine(m.Value);
    WriteLine(m.ToString());
  }

  static void f1()
  {
    Regex r = new Regex("Jen(ny|nifer)",
      RegexOptions.Compiled
      | RegexOptions.CultureInvariant);
    WriteLine(r.IsMatch("Jenny"));
  }

  static void f2()
  {
    WriteLine(Regex.Escape(@"?"));
    WriteLine(Regex.Unescape(@"\?"));
  }

  static void f3()
  {
    WriteLine(Regex.Matches("That is that.", "[Tt]hat").Count);
  }

  static void f4()
  {
    WriteLine(Regex.Match("say 25 miles more", @"\d+\s(?=miles)"));
  }

  private static void f5()
  {
    string password = "a4*&cb3_(*w";
    bool ok = Regex.IsMatch(password, @"^(?=.*\d).{6,10}$");
    WriteLine(ok);
  }

  private static void f6()
  {
    string regex = "(?i)(?<!however.*)good";
    WriteLine(Regex.IsMatch("However good, we...", regex));
    WriteLine(Regex.IsMatch("Very good, thanks!", regex));
  }

  public static bool f7(string input)
  {
    string pwPattern_ = @"^(?=.*\d).{8,16}$";
    Regex pattern_ = new Regex(pwPattern_, RegexOptions.Compiled);
    return pattern_.IsMatch(input);
  }
    
  static void Main(string[] args)
  {
    f7("fdsla1jewr");
  }
}