using System.Reactive.Linq;

var observable_ = "Hello, Rx".ToObservable();
var disposable_ = observable_.Subscribe(Console.WriteLine);
Console.ReadLine();