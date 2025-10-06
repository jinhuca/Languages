using System.Reactive.Linq;
using Helpers;

namespace P147;

internal class P147Program
{
  static void Main(string[] args)
  {
    //TakeConditionally();
    //TakeSubrange();
    //Resubscribe();
    AddSideEffectsInObservable();
  }

  private static void TakeConditionally()
  {
    IObservable<string> messages = new[] { "A", "B", "C", "D", "E" }.ToObservable();
    IObservable<string> controlChannel = new[] { "1", "2", "3", "STOP" }.ToObservable();

    messages
      .TakeUntil(controlChannel.Where(msg => msg == "STOP"))
      .Subscribe(
        msg => { Console.WriteLine(msg); },
        ex => { Console.WriteLine(ex.Message); },
        () => { });

    Console.ReadLine();
  }

  static void TakeSubrange()
  {
    Observable.Range(1, 10)
      .SkipWhile(x => x < 2)
      .TakeWhile(x => x < 7)
      .SubscribeConsole();
    Console.ReadLine();
  }

  static void Resubscribe()
  {
    Observable.Range(1,3)
      .Repeat(2)
      .SubscribeConsole("Repeat");
  }

  static void AddSideEffectsInObservable()
  {
    Observable.Range(1, 5)
      .Log("range")
      .Where(x => x % 2 == 0)
      .Log("where")
      .Select(x => x * 3)
      .SubscribeConsole("Final");
  }
}