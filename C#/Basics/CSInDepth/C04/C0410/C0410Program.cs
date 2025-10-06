namespace C0410;

internal class C0410Program
{
  static void Main(string[] args)
  {
    IEnumerable<string> strings_ = new List<string> { "a", "b", "c" };
    IEnumerable<object> objects_ = strings_;

    IList<string> strings1_ = new List<string> { "a", "b", "c" };
  }
}