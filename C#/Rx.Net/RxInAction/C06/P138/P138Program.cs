using System.Reactive.Linq;
using static System.Console;

namespace P138;

internal class P138Program
{
  static void Main(string[] args)
  {
    //CreateWithFullSubscribeOverload();
    //CreateWithOnlyOnNext();
    //ImplementOnError();
    PassAsyncWithoutOnError();
  }

  private static void CreateWithFullSubscribeOverload()
  {
    Observable.Range(1, 5)
      .Subscribe(
        x => WriteLine($"OnNext({x})"),
        ex => WriteLine($"OnError {ex.Message}"),
        () => WriteLine("OnCompleted"));
  }

  private static void CreateWithOnlyOnNext()
  {
    Observable.Range(1, 5)
      .Select(x => x / (x - 3))
      .Subscribe(WriteLine);
  }

  private static void CreateAndSubscribe()
  {
    try
    {
      Observable.Range(1, 5)
        .Select(x => x / (x - 3))
        .Subscribe(WriteLine);
    }
    catch (Exception e)
    {
      WriteLine(e);
      throw;
    }
  }

  private static void ImplementOnError()
  {
    Observable.Range(1, 5)
      .Select(x => x / (x - 3))
      .Subscribe(
        WriteLine,
        ex => { WriteLine($"{ex.Message}");});
  }

  private static void PassAsyncWithoutOnError()
  {
    Observable.Range(1, 5)
      .Select(x => Task.Run(() => x / (x - 3)))
      .Concat()
      .Subscribe(WriteLine);

    WriteLine("Press any key to continue...");
    ReadKey();
  }
}