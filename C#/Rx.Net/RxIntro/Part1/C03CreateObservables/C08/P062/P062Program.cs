using System.Reactive.Subjects;
using static System.Console;

namespace P062;

internal class P062Program
{
  static void Main()
  {
    AsyncSubject<string> subject_ = new();
    subject_.OnNext("a");
    subject_.Subscribe(x => WriteLine($"Sub1: {x}"));

    subject_.OnNext("b");
    subject_.OnNext("c");
    subject_.OnCompleted();

    subject_.Subscribe(x => WriteLine($"Sub2: {x}"));
    ReadKey();
  }
}