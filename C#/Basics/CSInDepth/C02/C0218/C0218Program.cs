namespace C0218;

internal class C0218Program
{
  static void Main()
  {
    foreach (var line_ in ReadLines("textFile.txt"))
    {
      Console.WriteLine(line_);
    }
  }

  static IEnumerable<string> ReadLines(string path)
  {
    using (TextReader reader = File.OpenText(path))
    {
      string line;
      while ((line = reader.ReadLine()) != null)
      {
        yield return line;
      }
    }
  }
}