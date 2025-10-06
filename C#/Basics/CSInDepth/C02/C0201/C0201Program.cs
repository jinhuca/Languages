namespace C0201
{
  internal class C0201Program
  {
    static void Main(string[] args)
    {
      PrintNames(GenerateNames());
    }

    static string[] GenerateNames()
    {
      string[] names = new string[4];
      names[0] = "Gamma";
      names[1] = "Vissides";
      names[2] = "Johnson";
      names[3] = "Helm";
      return names;
    }

    static void PrintNames(string[] names)
    {
      foreach (var name_ in names)
      {
        Console.WriteLine(name_);
      }
    }
  }
}
