using Helpers;
using System.Reactive;
using System.Reactive.Concurrency;
using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

namespace P234Schedulers;

internal class P234Program
{
  static void Main(string[] args)
  {
    //BasicScheduler();
    //MoreSchedulers();
    //ParamConcurrency1();
    //ScheduleRange();
    ImmediateSchedulerDemo();
  }

  static void BasicScheduler()
  {
    IScheduler scheduler = NewThreadScheduler.Default;
    IDisposable scheduling = scheduler
      .Schedule(
        state: Unit.Default,
        dueTime: TimeSpan.FromSeconds(2),
        action: (iScheduler, s) => {
          WriteLine($"Action scheduled at:\tThread #{Environment.CurrentManagedThreadId}:\t {iScheduler.Now.UtcDateTime}");
          return Disposable.Empty;
        });
    
    WriteLine($"Start main thread at:\tThread #{Environment.CurrentManagedThreadId}:\t {DateTime.Now.ToUniversalTime()}");
    ReadLine();
    scheduling.Dispose();
  }

  static void MoreSchedulers()
  {
    IScheduler scheduler = NewThreadScheduler.Default;
    Func<IScheduler, int, IDisposable>? action = null;

    action = (scdlr, callNumber) =>
    {
      WriteLine($"Action {callNumber} scheduled at:\tThread: {Environment.CurrentManagedThreadId}:\t {scdlr.Now.UtcDateTime}");
      return scdlr.Schedule(callNumber + 1, TimeSpan.FromSeconds(2), action);
    };

    IDisposable scheduling = scheduler.Schedule(
      0,
      TimeSpan.FromSeconds(2),
      action);

    WriteLine($"Start main thread at:\tThread #{Environment.CurrentManagedThreadId}:\t {DateTime.Now.ToUniversalTime()}");
    ReadLine();
    scheduling.Dispose();
  }

  static void ParamConcurrency1()
  {
    WriteLine($"Before - Thread: {Environment.CurrentManagedThreadId}");
    Observable.Interval(TimeSpan.FromSeconds(1), CurrentThreadScheduler.Instance)
      .Take(3)
      .Subscribe(x => WriteLine($"Inside - Thread: {Environment.CurrentManagedThreadId} with {x}"));
    ReadLine();
  }

  static void ScheduleRange()
  {
    var subscription = Observable
      .Range(1, 5)
      .SubscribeConsole("Range on another thread");
    ReadLine();
    subscription.Dispose();
  }

  static void ImmediateSchedulerDemo()
  {
    var immediateScheduler = ImmediateScheduler.Instance;
    WriteLine($"Calling thread# {Environment.CurrentManagedThreadId} at current time: {immediateScheduler.Now.UtcDateTime}");
    immediateScheduler.Schedule(
      Unit.Default,
      TimeSpan.FromSeconds(2),
      (s, _) =>
      {
        WriteLine($"Outer Action - Thread: {Environment.CurrentManagedThreadId}");
        s.Schedule(
          Unit.Default,
          (s2, __) =>
          {
            WriteLine($"Inner Action - Thread: {Environment.CurrentManagedThreadId}");
            return Disposable.Empty;
          });
        WriteLine("Outer Action - Done");
        return Disposable.Empty;
      });
    WriteLine($"After the Schedule, Time: {immediateScheduler.Now.UtcDateTime}");
  }
}
