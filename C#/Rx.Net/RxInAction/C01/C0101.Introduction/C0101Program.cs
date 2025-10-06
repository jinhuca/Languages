using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

var strings = new[] { "Hello", "Rx", "A", "AB" }.ToObservable();

WriteLine("A - run to completion.");
IDisposable subscription = strings
  .Where(str => str.StartsWith("A", StringComparison.Ordinal))
  .Select(str => str.ToUpper())
  .Subscribe(WriteLine);

subscription.Dispose();

ReadLine();

WriteLine("B - add item on Observable after subscription.");
IObservable<string> sub1 = strings
  .Where(str => str.StartsWith("A", StringComparison.Ordinal))
  .Select(str => str.ToUpper());

strings = strings.Append("ABC");
sub1.Subscribe(WriteLine);

ReadLine();

WriteLine("C - push an exception on observable, and it is unhandled on observer. - crash / terminate the app.");
var sub2 = Observable.Create<string>(observer =>
{
  observer.OnNext("Hello");
  observer.OnError(new Exception());
  return Disposable.Empty;
});

sub2.Subscribe(WriteLine);
ReadLine();