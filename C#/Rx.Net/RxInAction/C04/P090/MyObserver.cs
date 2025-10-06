using static System.Console;

namespace P090;

internal sealed class MyObserver(string name = "") : IObserver<int>
{
  public void OnCompleted()
  {
    WriteLine($"{name} - OnCompleted()");
  }

  public void OnError(Exception error)
  {
    WriteLine($"{name} - OnError()");
    WriteLine($"\t {error}");
  }

  public void OnNext(int value)
  {
    WriteLine($"{name} - OnNext({value})");
  }
}

internal sealed class MyAnotherObserver<T> : IObserver<T>
{
  private readonly string _name;

  public MyAnotherObserver(string name = "")
  {
    _name = name;
  }

  public void OnNext(T value)
  {
    WriteLine($"{_name} - OnNext({value})");
  }

  public void OnCompleted()
  {
    WriteLine($"{_name} - OnCompleted()");
  }

  public void OnError(Exception error)
  {
    WriteLine($"{_name} - OnError: \t {error}");
  }
}