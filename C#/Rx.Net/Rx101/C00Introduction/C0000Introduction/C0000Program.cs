using System.Reactive.Linq;

namespace C0000Introduction;

internal class C0000Program
{
  static void Main(string[] args)
  {
    CreateObservableDemo();
  }

  static void CreateObservableDemo()
  {
    var observable_ = Observable.Range(5, 8);
    var subscription_ = observable_.Subscribe(new Observer());
    subscription_.Dispose();
  }
}

internal class Observer:IObserver<int>
{
  public void OnNext(int value)
  {
    Console.WriteLine($"Received value {value}");
  }

  public void OnCompleted()
  {
    Console.WriteLine("Observation completed.");
  }

  public void OnError(Exception error)
  {
    Console.WriteLine($"Error {error.Message}");
  }
}