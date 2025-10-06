using System.Reactive.Linq;
using SampleExtensions;

IObservable<int> xs_ = Observable.Range(1, 3);
IObservable<int> dropEverything_ = xs_.IgnoreElements();

dropEverything_.Dump("IgnoreElements");