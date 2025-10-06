using System.Reactive.Linq;
using static System.Console;
using System.Reactive.Disposables;

IObservable<string> throws_ = Observable.Throw<string>(new Exception());

throws_.Subscribe(
  value => WriteLine($"Received {value}"),
  error => WriteLine($"Received Error {error}"),
  () => WriteLine("Completed."));
Read();

SomeNumbers().Subscribe(
  value => WriteLine($"Received {value}"),
  error => WriteLine($"Received Error {error}"),
  () => WriteLine("Completed."));

IObservable<int> SomeNumbers() => Observable.Create((IObserver<int> observer) =>
{
  observer.OnNext(1);
  observer.OnNext(2);
  observer.OnNext(3);
  observer.OnCompleted();
  return Disposable.Empty;
});