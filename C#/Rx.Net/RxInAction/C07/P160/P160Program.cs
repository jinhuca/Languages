using System.Reactive.Subjects;
using Helpers;

Subject<int> sbj = new Subject<int>();

sbj.SubscribeConsole("First");
sbj.SubscribeConsole("Second");

sbj.OnNext(1);
sbj.OnNext(2);
sbj.OnCompleted();
