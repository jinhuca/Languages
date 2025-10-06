using Helpers;
using System.Reactive.Linq;
using System.Reactive.Subjects;

IObservable<int> heartRate = Observable.Range(70, 5);
ReplaySubject<int> sbj = new ReplaySubject<int>(bufferSize: 20, window: TimeSpan.FromMinutes(2));

heartRate.Subscribe(sbj);

var subscription = sbj.SubscribeConsole("HeartRate Graph");   // only 70-74 will be observed
Console.ReadLine();
subscription.Dispose();