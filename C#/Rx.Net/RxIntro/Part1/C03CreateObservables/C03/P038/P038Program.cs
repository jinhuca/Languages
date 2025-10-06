using System.Reactive.Linq;
using static System.Reactive.Linq.Observable;
using static System.Console;

namespace P038_1;

internal class P038Program
{
  static void Main()
  {
    EmptyDemo();
  }

  private static void EmptyDemo()
  {
    var empty_ = Empty<string>();
    empty_.Subscribe(
      value => WriteLine($"{value}"),
      error => WriteLine($"Received Error {error}."),
      () => WriteLine("Completed."));
  }

  private static void NeverDemo()
  {
    var never_ = Never<string>();
    never_.Subscribe(value => WriteLine($"{value}"));
  }
}