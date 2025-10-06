using System.Reactive.Linq;
using static System.Console;

namespace P141;

internal class P141Program
{
  static void Main()
  {
    PassCancelToken();
    ReadLine();
  }

  static void PassCancelToken()
  {
    var cts = new CancellationTokenSource();
    cts.Token.Register(() => WriteLine("Subscription cancelled."));

    Observable.Interval(TimeSpan.FromSeconds(1))
      .Subscribe(WriteLine, cts.Token);

    cts.CancelAfter(TimeSpan.FromSeconds(5));
  }
}