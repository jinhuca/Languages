using System.Reactive.Linq;
using static System.Console;

namespace P055;

internal class P055Program
{
  static void Main()
  {
    //FromTaskDemo1();
    FromTaskDemo2();
  }

  private static void FromTaskDemo1()
  {
    IObservable<string> source_ = Observable.FromAsync(() => Task.Run(() =>
    {
      WriteLine("Task running ...");
      return "Test";
    }));

    source_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));

    source_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));

    ReadKey();
  }

  private static void FromTaskDemo2()
  {
    IObservable<string> source_ = Observable.FromAsync(async () =>
    {
      WriteLine("Task running ...");
      await Task.Delay(50);
      return "Test";
    });
    
    source_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));

    ReadKey();
  }
}