using System.Reactive.Linq;
using static System.Console;

namespace P050;

internal class P050Program
{
  static void Main()
  {
    StartAction();
    StartFunc();
    ReadLine();
  }

  static void StartAction()
  {
    var start_ = Observable.Start(() =>
    {
      Write("Working away");
      for (int i = 0; i < 10; i++)
      {
        Thread.Sleep(100);
        Write(".");
      }
    });

    start_.Subscribe(
      unit => WriteLine("Unit published"),
      () => WriteLine("Action completed"));
  }

  static void StartFunc()
  {
    var start_ = Observable.Start(() =>
    {
      WriteLine("Working away");
      for (int i = 0; i < 10; i++)
      {
        Thread.Sleep(100);
        Write(".");
      }

      return "Published value";
    });

    start_.Subscribe(
      WriteLine,
      () => WriteLine("Func completed"));
  }
}