namespace C0210;

internal class C0210Program
{
  static void Main(string[] args)
  {
    GetTypeNullable();
  }

  static void GetTypeNullable()
  {
    Nullable<int> noValue = new Nullable<int>();
    //Console.WriteLine(noValue.GetType());

    Nullable<int> someValue = new Nullable<int>(5);
    Console.WriteLine(someValue.GetType());
  }
}

