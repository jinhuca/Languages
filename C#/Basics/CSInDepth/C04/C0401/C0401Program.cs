namespace C0401;

internal class C0401Program
{
  static void Main()
  {
    dynamic text = "Hello world";
    Console.WriteLine(text.GetType());
    string world = text.Substring(6);
    Console.WriteLine(world);

    string broken = text.SUBSTR(6);
    Console.WriteLine(broken);
  }
}