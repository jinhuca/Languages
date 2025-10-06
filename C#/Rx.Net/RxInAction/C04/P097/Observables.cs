using System.Reactive.Disposables;
using System.Reactive.Linq;

namespace P097;

internal class Observables
{
  public static IObservable<int> CreateObservableNumbers(int amount)
  {
    return Observable.Create<int>(observer =>
    {
      for (int i = 0; i < amount; i++)
      {
        observer.OnNext(i);
      }
      observer.OnNext(99);
      observer.OnCompleted();
      
      return Disposable.Create(() => {
          Console.WriteLine($"{nameof(CreateObservableNumbers)} is disposed!");
        });
    });
  }

  public static IObservable<int> CreateSequence(int amount)
  {
    return Observable.Generate(
      0,                // initial state
      i => i < amount,  // condition (false means terminate)
      i => i + 1,       // next iteration step
      i => i + 2);      // the value in each iteration
  }
}