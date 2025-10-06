using static System.Console;

namespace C0201;

file class C0201Program
{
  static void Main(string[] args)
  {
    DotProductDemo();
  }

  private static void DotProductDemo()
  {
    int[] v1_ = { 1, 2, 3 };
    int[] v2_ = { 3, 2, 1 };
    var zipped_ = v1_.Zip(v2_, (a, b) => a * b);
    foreach (var z in zipped_)
    {
      WriteLine(z);
    }
  }
}