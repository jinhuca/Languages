// See https://aka.ms/new-console-template for more information

using System.Reactive.Concurrency;
using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

WriteLine("Hello, World!");

IObservable<int> ob = Observable.Create<int>(o =>
{
  var cancel_ = new CancellationDisposable(); // internally creates a new CancellationTokenSource 
  NewThreadScheduler.Default.Schedule(() =>
  {
    int i = 0;
    for (; ; )
    {
      Thread.Sleep(200);  // here we do the long lasting background operation
      if (!cancel_.Token.IsCancellationRequested)    // check cancel token periodically
      {
        o.OnNext(i++);
      }
      else
      {
        WriteLine("Aborting because cancel event was signaled!");
        o.OnCompleted(); // will not make it to the subscriber
        return;
      }
    }
  });
  return cancel_;
});

var subscription_ = ob.Subscribe(WriteLine);
WriteLine("Press any key to cancel");
ReadKey();
subscription_.Dispose();
WriteLine("Press any key to quit");
ReadKey();  // give background thread chance to write the cancel acknowledge message