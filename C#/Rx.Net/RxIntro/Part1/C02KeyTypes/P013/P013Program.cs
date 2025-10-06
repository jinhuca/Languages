using System.Reactive.Concurrency;
using System.Reactive.Linq;

namespace P013;

file class P013Program
{
  static async Task Main()
  {
    var source = new List<int> { 1, 2, 3 }.ToObservable();
    await source.Quiescent(TimeSpan.FromSeconds(2), Scheduler.Default);
  }
}

file static class RxExt
{
  public static IObservable<IList<T>> Quiescent<T>(
    this IObservable<T> src,
    TimeSpan minimumInactivityPeriod,
    IScheduler scheduler)
  {
    IObservable<int> onoffs_ = src.SelectMany(_ =>
      Observable
        .Return(1, scheduler)
        .Concat(Observable.Return(-1, scheduler).Delay(minimumInactivityPeriod, scheduler)));

    IObservable<int> outstanding = onoffs_.Scan(0, (total, delta) => total + delta);
    
    IObservable<int> zeroCrossings = outstanding.Where(total => total == 0);
    
    return src.Buffer(zeroCrossings);
  }
}
