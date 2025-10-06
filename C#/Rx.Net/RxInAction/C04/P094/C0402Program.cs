namespace P094; 

using Helpers;
using System.Reactive.Disposables;
using System.Reactive.Linq;

file class C0402Program
{
  static void Main()
  {
    //EnforcingUnsubscribingObservers();
    ChatExample.Run();
    Console.ReadLine();
  }

  public static IObservable<int> ObserveNumbers(int amount)
  {
    return Observable.Create<int>(observer =>
    {
      for (int i = 0; i < amount; i++)
      {
        observer.OnNext(i);
      }

      observer.OnCompleted();
      return Disposable.Empty;
    });
  }

  private static void EnforcingUnsubscribingObservers()
  {
    Console.WriteLine();
    IObservable<int> errorTestObservable = new ErrorNumbersObservable(5);
    
    var consoleObserver = new ConsoleObserver<int>("errorTest");
    Console.WriteLine("the contract is not enforced in the manual observable");
    var subscription = errorTestObservable.Subscribe(consoleObserver);

    Console.WriteLine();
    Console.WriteLine("however, the Observable.Create(...) version does enforce");
    errorTestObservable = Observable.Create<int>(o => 
    {
      o.OnNext(1);
      o.OnError(new ApplicationException());
      o.OnNext(2);
      o.OnCompleted();
      o.OnNext(3);
      return Disposable.Empty;
    });
    subscription = errorTestObservable.Subscribe(consoleObserver);
  }
}