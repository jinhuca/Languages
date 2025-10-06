using System.Reactive.Concurrency;
using System.Reactive.Linq;

namespace RxLibrary;

public static class ObservableExtensions
{
  public static IObservable<T> FilterBursts<T>(this IObservable<T> src, int burstSize)
  {
    return src.Window(burstSize).SelectMany(window => window.Take(1));
  }

  public static IObservable<T> FilterBursts<T>(this IObservable<T> src, TimeSpan maximalDistance)
  {
    return src.FilterBursts(maximalDistance, DefaultScheduler.Instance);
  }

  public static IObservable<T> FilterBursts<T>(
    this IObservable<T> src, 
    TimeSpan maximalDistance,
    IScheduler scheduler)
  {
    return src.Publish(xs =>
    {
      var windowBoundaries = xs.Throttle(maximalDistance, scheduler);

      return xs.Window(windowBoundaries).SelectMany(window => window.Take(1));
    });
  }

  public static IObservable<T> FilterBursts<T>(
    this IObservable<T> src,
    TimeSpan maximalDistance,
    TimeSpan maximalBurstDuration,
    IScheduler scheduler)
  {
    return src.Publish(xs =>
    {
      var maximDurationPassed = xs.Delay(maximalBurstDuration, scheduler).Take(1);
      var windowBoundary = xs.Throttle(maximalDistance, scheduler).Merge(maximDurationPassed);

      return xs.Window(() => windowBoundary).SelectMany(window => window.Take(1));
    });
  }
}