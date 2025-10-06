using System.Dynamic;

namespace C0405;

internal class C0405Program
{
  static void Main()
  {
    dynamic expando_ = new ExpandoObject();
    expando_.SomeData = "Some data";
    Action<string> action_ = input => Console.WriteLine("The input was '{0}'.", input);
    expando_.FakeMethod = action_;

    Console.WriteLine(expando_.SomeData);
    expando_.FakeMethod("hello");

    IDictionary<string, object> dictionary_ = expando_;
    Console.WriteLine("Keys: {0}", string.Join(", ", dictionary_.Keys));

    dictionary_["OtherData"] = "other";
    Console.WriteLine(expando_.OtherData);
  }
}