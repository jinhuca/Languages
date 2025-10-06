namespace C0212;

internal class C0212Program
{
  static void Main(string[] args)
  {
    IEnumerable<int> enumerable = CreateSimpleIterator();
    IEnumerator<int> enumerator = enumerable.GetEnumerator();
    while(enumerator.MoveNext())
    {
      int value = enumerator.Current;
      Console.WriteLine(value);
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
