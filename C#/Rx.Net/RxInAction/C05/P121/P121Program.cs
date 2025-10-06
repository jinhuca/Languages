using System.Reactive.Linq;
using Helpers;
using P121.SearchEngine;
using P121.Services;

namespace P121;

internal class P121Program
{
  static void Main()
  {
    //SearchWithAsyncAwait();
    //SearchWithConcatTasks();
    RunAsyncCodeInWhere();
  }

  public static void SearchWithAsyncAwait()
  {
    var results = SearchEngineExample.Search_WithAsyncAwait("Rx");
    results.RunExample("Search async-await");
  }

  public static void SearchWithConcatTasks()
  {
    var results = SearchEngineExample.Search_ConcatTasks("Rx");
    results.RunExample("Task to observables");
  }

  public static void RunAsyncCodeInWhere()
  {
    var svc = new PrimeCheckService();

    IObservable<int> primes =
      Observable.Range(1, 10)
        .SelectMany(
          number => svc.IsPrimeAsync(number),
          (number, isPrime) => new { number, isPrime })
        .Where(x => x.isPrime)
        .Select(x => x.number);

    var exampleResetEvent = new AutoResetEvent(false);
    primes.DoLast(() => exampleResetEvent.Set(), TimeSpan.FromSeconds(1))
      .SubscribeConsole("primes");

    exampleResetEvent.WaitOne();
  }

  public static void ControlOrderOfAsyncCode()
  {
    var resetEvent = new AutoResetEvent(false);
    Console.WriteLine("Using SelectMany wont maintain items order");
    var svc = new VariableTimePrimeCheckService(numberToDelay: 3);
    IObservable<int> primes =
      from number in Observable.Range(1, 10)
      from isPrime in svc.IsPrimeAsync(number)
      where isPrime
      select number;

    primes
      .DoLast(() => resetEvent.Set(), delay: TimeSpan.FromSeconds(1))
      .SubscribeConsole("primes - unordered");

    // Waiting for the previous example to finish
    resetEvent.WaitOne();

    Console.WriteLine("Using concat does enforce order");
    primes =
      Observable.Range(1, 10)
        .Select(async (number) => new { number, IsPrime = await svc.IsPrimeAsync(number) })
        .Concat()
        .Where(x => x.IsPrime)
        .Select(x => x.number);

    primes.SubscribeConsole("primes");

    // Waiting for the previous example to finish
    resetEvent.WaitOne();
  }
}