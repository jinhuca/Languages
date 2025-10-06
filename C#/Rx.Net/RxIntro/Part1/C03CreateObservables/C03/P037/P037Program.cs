using System.Reactive.Linq;
using static System.Console;

IObservable<string> singleValue_ = Observable.Return<string>("Value");
singleValue_.Subscribe(
  value => WriteLine($"Received {value}"),
  error => WriteLine($"Received Error {error}"),
  () => WriteLine("Completed."));
Read();
