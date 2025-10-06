using System.Reactive.Linq;
using static System.Console;

WriteLine("Press any key to stop.");

IObservable<long> ticks_ = Observable.Timer(
  dueTime: TimeSpan.Zero,
  period: TimeSpan.FromSeconds(1));

ticks_.Subscribe(tick => WriteLine($"Tick: {tick}"));

Read();
