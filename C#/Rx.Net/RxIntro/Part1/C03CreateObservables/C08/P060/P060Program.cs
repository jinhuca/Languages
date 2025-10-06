using System.Reactive.Subjects;
using static System.Console;

namespace P060;

internal class P060Program
{
  static void Main()
  {
    //ReplaySubjectDemo();
    ReplaySubjectWithCacheDemo();
  }

  private static void ReplaySubjectDemo()
  {
    ReplaySubject<int> s_ = new();
    s_.Subscribe(x => WriteLine($"Sub1: {x}"));
    s_.OnNext(1);
    s_.OnNext(2);

    s_.Subscribe(x => WriteLine($"Sub2: {x}"));
    s_.OnNext(3);

    ReadKey();
  }

  private static void ReplaySubjectWithCacheDemo()
  {
    ReplaySubject<int> s_ = new(2);
    s_.Subscribe(x => WriteLine($"Sub1: {x}"));

    s_.OnNext(1);
    s_.OnNext(2);
    s_.OnNext(3);

    s_.Subscribe(x => WriteLine($"Sub2: {x}"));
    s_.OnNext(4);

    ReadKey();
  }
}