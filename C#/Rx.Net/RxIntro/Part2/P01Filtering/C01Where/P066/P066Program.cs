using System.Reactive.Linq;
using SampleExtensions;
using static System.Console;

IObservable<int> xs_ = Observable.Range(0, 10);
IObservable<int> evenNumbers_ = xs_.Where(i => i % 2 == 0);
evenNumbers_.Dump("Where");

IObservable<int> dropEverything_ = xs_.Where(_ => false);

dropEverything_.Subscribe(
  WriteLine,
  () => WriteLine("completed"));

ReadKey();