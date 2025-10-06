namespace C0204;

internal class C0204Program
{
  static void Main(string[] args)
  {
    PrintNames(GenerateName());
  }

  static List<string> GenerateName()
  {
    List<string> names_ = new List<string>();
    names_.Add("Gamma");
    names_.Add("Johnson");
    return names_;
  }

  static void PrintNames(List<string> names)
  {
    foreach (var name_ in names)
    {
      Console.WriteLine(name_);
    }
  }
}