namespace C0205;

internal class C0205Program
{
  static void Main()
  {
    FindDominator();
  }

  static void FindDominator()
  {
    int[] array = { 3, 4, 3, 2, 3, -1, 3, 3 };
    var s = array.ToLookup(a => a).First(a => a.Count() > array.Length / 2);
    foreach (var item_ in s)
    {
      
    }
  }
}