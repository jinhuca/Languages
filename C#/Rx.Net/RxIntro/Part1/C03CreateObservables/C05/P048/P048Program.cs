using System.Reactive.Linq;
using static System.Console;
using static System.TimeSpan;

namespace P048;

internal class P048Program
{
  static void Main()
  {
    TimerDemo1();
    //TimerDemo2();
  }

  private static void TimerDemo1()
  {
    var timer_ = Observable.Timer(FromSeconds(1));

    timer_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));

    ReadLine();
  }

  private static void TimerDemo2()
  {
    var timer_ = Observable.Timer(FromSeconds(1), FromSeconds(3));

    timer_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));
    
    ReadLine();
  }
}