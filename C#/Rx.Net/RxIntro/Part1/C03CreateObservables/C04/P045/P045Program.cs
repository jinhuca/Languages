using System.Reactive.Linq;

IObservable<int> range_ = Observable.Range(10, 15);
range_.Subscribe(Console.WriteLine, () => Console.WriteLine("Completed"));