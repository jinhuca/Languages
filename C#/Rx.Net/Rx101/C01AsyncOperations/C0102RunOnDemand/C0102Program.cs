// Synchronous operation
// Run a method asynchronously on demand
// Execute a long-running method asynchronously. 
// The method does not start until there is a subscriber.
// The method is started every time the observable is created and subscribed, so there could be more than one running at once.

using System.Reactive.Linq;
using static System.Console;

public class Program
{
  public static void Main()
  {
    WriteLine("Start Main Thread.");
    var observable_ = LongRunningOperationAsync("hello");
    WriteLine("Subscribe a method.");
    observable_.Subscribe(WriteLine);
    WriteLine("Waiting for asynchronous method complete.");
    ReadKey();
  }

  public static int DoLongRunningOperation(string param)
  {
    Thread.Sleep(3000);
    return 42;
  }

  public static IObservable<int> LongRunningOperationAsync(string param)
  {
    return Observable.Create<int>(observer => Observable.ToAsync<string, int>(DoLongRunningOperation)(param).Subscribe(observer));
  }
}
