// CombineLatest - Parallel Execution

using System.Reactive.Linq;
using static System.Threading.Thread;

public class Program
{
  public static async Task Main()
  {
    ParallelExecutionTest();
  }

  // Merges the specified observable sequences into one observable sequence by emitting a list
  // with the latest source elements whenever any of the observable sequences produces an element.
  public static async void ParallelExecutionTest()
  {
    var observable_ = Observable
      .CombineLatest(
        Observable.Start(() =>
        {
          Console.WriteLine($"Executing 1st on Thread: {CurrentThread.ManagedThreadId}");
          return "Result A";
        }),
        Observable.Start(() =>
        {
          Console.WriteLine($"Executing 1st on Thread: {CurrentThread.ManagedThreadId}");
          return "Result B";
        }),
        Observable.Start(() =>
        {
          Console.WriteLine($"Executing 1st on Thread: {CurrentThread.ManagedThreadId}");
          return "Result C";
        }))
      .Finally(() => Console.WriteLine("Done!"));

    foreach (var result_ in await observable_)
    {
      Console.WriteLine(result_);
    }
  }
}