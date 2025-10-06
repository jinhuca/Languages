using System.Reactive;
using System.Reactive.Concurrency;
using System.Reactive.Linq;
using System.Reflection.Metadata.Ecma335;
using static System.Console;

namespace Helpers;

public static class Extensions
{    
  /// <summary>
  /// Subscribe an observer that prints each notification to the console output
  /// </summary>
  /// <typeparam name="T"></typeparam>
  /// <param name="observable"></param>
  /// <param name="name"></param>
  /// <returns>a disposable subscription object</returns>
  public static IDisposable SubscribeConsole<T>(this IObservable<T> observable, string name = "")
  {
    return observable.Subscribe(new ConsoleObserver<T>(name));
  }

  /// <summary>
  /// this method does the same as SubscribeConsole but uses Observable.Subscribe() method instead of a handcrafted observer class
  /// </summary>
  /// <typeparam name="T"></typeparam>
  /// <param name="observable"></param>
  /// <param name="name"></param>
  /// <returns></returns>
  public static IDisposable SubscribeTheConsole<T>(this IObservable<T> observable, string name = "")
  {
    return observable.Subscribe(
      x => WriteLine($"{name} - OnNext({x})"),
      ex => { WriteLine($"{name} - OnError:\t {ex}"); },
      () => WriteLine("{0} - OnCompleted()", name));
  }

  public static IObservable<T> DoLast<T>(this IObservable<T> observable, Action lastAction, TimeSpan? delay = null)
  {
    Action delayedLastAction_ = async () =>
    {
      if (delay.HasValue)
      {
        await Task.Delay(delay.Value);
      }
      lastAction();
    };
    return observable.Do(
      (_) => { },//empty OnNext
      _ => delayedLastAction_(),
      delayedLastAction_);
  }

  public static void RunExample<T>(this IObservable<T> observable, string exampleName = "")
  {
    var exampleResetEvent = new AutoResetEvent(false);

    observable
      .DoLast(() => exampleResetEvent.Set(), TimeSpan.FromSeconds(3))
      .SubscribeConsole(exampleName);

    exampleResetEvent.WaitOne();
  }

  public static IObservable<T> Log<T>(this IObservable<T> observable, string msg = "")
  {
    return observable.Do(
      x => WriteLine($"{msg} - OnNext({x})"),
      ex =>
      {
        WriteLine($"{msg} - OnError:\t{ex}");
      },
      () => WriteLine($"{msg} - OnCompleted()"));
  }

  public static IObservable<T> LogWithThread<T>(this IObservable<T> observable, string msg = "")
  {
    return Observable.Defer(() =>
    {
      WriteLine($"{msg} Subscription happened on Thread: {Thread.CurrentThread.ManagedThreadId}");

      return observable.Do(
        x => WriteLine($"{msg} - OnNext({x}) Thread: {Thread.CurrentThread.ManagedThreadId}"),
        ex =>
        {
          WriteLine($"{msg} - OnError Thread:{Thread.CurrentThread.ManagedThreadId}");
          WriteLine($"\t {ex}");
        },
        () => WriteLine($"{msg} - OnCompleted() Thread {Thread.CurrentThread.ManagedThreadId}"));
    });
  }

  public static void TestScheduler(IScheduler scheduler)
  {
    scheduler.Schedule(
      Unit.Default,
      (s, _) => WriteLine($"Action1 - Thread: {Environment.CurrentManagedThreadId}"));
    scheduler.Schedule(
      Unit.Default,
      (s, _) => WriteLine($"Action2 - Thread: {Environment.CurrentManagedThreadId}"));
  }
}