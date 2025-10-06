using System.Reactive.Linq;
using SampleExtensions;

IObservable<int> numbers_ = Observable.Range(0, 3);
numbers_.Count().Dump("count");
