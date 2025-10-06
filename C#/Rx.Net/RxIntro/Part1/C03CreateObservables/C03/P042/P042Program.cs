using System.Reactive.Linq;
using static System.Console;

namespace P042;

internal class P042Program
{
  static void Main()
  {
    string _path = "testfile.txt";
    GenerateFileLines(_path).Subscribe(
      value => WriteLine($"Received {value}"),
      error => WriteLine($"Received error {error}"),
      () => WriteLine("Completed"));
    ReadLine();
  }

  private static IObservable<string> GenerateFileLines(string path)
  {
    return Observable.Create<string>(async (observer, cancellationToken) =>
    {
      using StreamReader reader = File.OpenText(path);
      while (cancellationToken.IsCancellationRequested)
      {
        string? line = await reader.ReadLineAsync(cancellationToken).ConfigureAwait(false);
        if (line is null)
        {
          break;
        }

        observer.OnNext(line);
      }

      observer.OnCompleted();
    });
  }
}