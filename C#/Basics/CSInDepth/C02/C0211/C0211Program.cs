namespace C0211;

internal class C0211Program
{
  static void Main()
  {
    foreach(var x in CreateSimpleIterator())
    {
      Console.WriteLine(x);
    }
  }

  static IEnumerable<int> CreateSimpleIterator()
  {
    yield return 10;
    for(int i = 0; i < 3; i++)
    {
      yield return i;
    }
    yield return 20;
  }
}
