using System.Collections.Specialized;

namespace C0203;

internal class C0203Program
{
  static void Main(string[] args)
  {
    PrintNames(GenerateNames());
  }

  static StringCollection GenerateNames()
  {
    StringCollection names_ = new StringCollection();
    names_.Add("Gamma");
    names_.Add("Johnson");
    return names_;
  }

  static void PrintNames(StringCollection names)
  {
    foreach (var name_ in names)
    {
      Console.WriteLine(name_);
    }
  }
}