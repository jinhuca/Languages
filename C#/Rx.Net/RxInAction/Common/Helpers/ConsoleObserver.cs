namespace Helpers;

public class ConsoleObserver<T>(string name = "") : IObserver<T>
{
  public void OnNext(T value) => WriteLine($"{name} - OnNext({value})");
  public void OnCompleted() => WriteLine($"{name} - OnCompleted()");
  public void OnError(Exception error) => WriteLine($"{name} - OnError:\t {error}");
}