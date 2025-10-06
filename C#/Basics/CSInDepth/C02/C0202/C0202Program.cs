using System.Collections;

namespace C0202;

internal class C0202Program
{
  static void Main(string[] args)
  {
    PrintNames(GenerateNames());
  }

  static ArrayList GenerateNames()
  {
    ArrayList names = new ArrayList();
    names.Add("Gamma");
    names.Add("Vlissides");
    names.Add("Johnson");
    names.Add("Helm");
    return names;
  }

  static void PrintNames(ArrayList names)
  {
    foreach (var name_ in names)
    {
      Console.WriteLine(name_);
    }
  }
}