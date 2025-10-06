namespace C0302;

internal class C0302Program
{
  static void Main(string[] args)
  {
    Action<string> action_ = (string messge) =>
    {
      Console.WriteLine(messge);
    };

    action_ += (string anotherMessage) =>
    {
      Console.WriteLine(anotherMessage);
    };

    action_("hello");
  }
}