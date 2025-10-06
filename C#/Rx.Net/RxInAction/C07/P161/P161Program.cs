using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;

Subject<string> sbj = new Subject<string>();

Observable.Interval(TimeSpan.FromSeconds(1))
  .Select(x => "First: " + x)
  .Take(5)
  .Subscribe(sbj);

Observable.Interval(TimeSpan.FromSeconds(2))
  .Select(x => "Second: " + x)
  .Take(5)
  .Subscribe(sbj);

sbj.SubscribeConsole();
Console.ReadLine();