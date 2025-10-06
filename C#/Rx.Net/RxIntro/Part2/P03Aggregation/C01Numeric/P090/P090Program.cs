using System.Reactive.Linq;
using SampleExtensions;

IObservable<int> numbers_ = Observable.Range(1, 5);
numbers_.Sum().Dump("sum");