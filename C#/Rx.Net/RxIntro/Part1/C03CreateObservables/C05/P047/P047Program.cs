using System.Reactive.Linq;
using static System.Console;
using static System.TimeSpan;

namespace P047;

internal class P047Program
{
  static void Main()
  {
    IObservable<long> interval_ = Observable.Interval(FromMilliseconds(250));

    interval_.Subscribe(
      WriteLine,
      () => WriteLine("completed"));

    Read();
  }
}