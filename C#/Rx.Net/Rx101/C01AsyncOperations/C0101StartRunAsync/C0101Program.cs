// Start - Run Code Asynchronously
//

using System.Reactive;
using System.Reactive.Linq;
using static System.Console;

WriteLine("Shows use of Start to start on a background thread:");
IObservable<Unit> observable_ = Observable
  .Start(() =>
  {
    // This starts on a background thread.
    WriteLine("From background thread. Does not block main thread.");
    WriteLine("Calculating...");
    Thread.Sleep(3000);
    WriteLine("Background work completed.");
  })
  .Finally(() => WriteLine("Main thread completed."));

WriteLine("\r\n\t In Main Thread...\r\n");
// Wait for completion of background operation.
observable_.Wait();