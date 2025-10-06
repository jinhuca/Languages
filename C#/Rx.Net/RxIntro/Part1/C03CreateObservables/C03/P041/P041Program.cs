using System.Reactive.Linq;
using static System.Console;

IObservable<char> KeyPresses() =>
  Observable.Create<char>(observer =>
  {
    CancellationTokenSource cts = new();
    Task.Run(() =>
    {
      while(!cts.IsCancellationRequested)
      {
        ConsoleKeyInfo ki = ReadKey();
        observer.OnNext(ki.KeyChar);
      }
    });

    return () => cts.Cancel();
  });

KeyPresses().Subscribe(
  k => WriteLine($"Received key = {k}"),
  e => WriteLine($"received error {e}"),
  () => WriteLine("Completed"));
ReadLine();
